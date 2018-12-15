#include <iostream>
#include <string>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int base = 1000000000;
int base_digits = 9;
/*bigint operations part is copied from net*/
struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
long long int seive(ll a,ll b,ll n,ll m)
{
																																																																																														        if(a>1000000000){
																																																																																														        ll p,q,r;
																																																																																														        char cad[100],cad1[100];
																																																																																																sprintf(cad,"%lld",a);
																/*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected
The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/																																																																																sprintf(cad1,"%lld",b);
																																																																																														        string kk1,kk2;
																																																																																														        kk1=cad;
																																																																																														        kk2=cad1;
																																																																																														        bigint a1,b1,a2,b2,k1,k2,k3,x1,x2;

																																																																																														        /*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.
The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																														        a1=bigint(kk1);
																																																																																														        b1=bigint(kk2);
																																																																																														        bigint two("2");
																																																																																														        bigint three("3");
																																																																																														        /*
																																																																																														        This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																														        k1=(a1*(a1+1)*(two*a1+1)*(three*a1*a1+three*a1-1))/30;
																																																																																														        k2=(b1*(b1+1)*(two*b1+1)*(three*b1*b1+three*b1-1))/30;
																																																																																														        x1=k1%m;
																																																																																														        x2=k2%m;
																																																																																														        k3=(x1-x2+m)%m;
																																																																																														        bigint x =k3;
																																																																																														        string s="";
																																																																																														/*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																														        while(x>0)
																																																																																														        {
																																																																																														                s += '0' + x%10;
																																																																																														                x /= 10;
																																																																																														        }
																																																																																														        /*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected
The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																														        ll out=0,i;
																																																																																														        for(i=s.size()-1;i>=0;i--)
																																																																																														        {
																																																																																														                out=out*10+(s[i]-48);
																																																																																														        }
																																																																																														        return out;
																																																																																														        }
																																																																																														        else
																																																																																														        {

																																																																																														                ll p,q,r,t,s,de;
																																																																																														        ll k1,k2,k3,k4,k5;
																																																																																														        ll a1=a;
																																																																																														        ll temp=a;
																																																																																														        k1=a;
																																																																																														        k2=a+1;
																																																																																														        k3=2*a+1;
																																																																																														/*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/

																							k4=((3*a)*(a) + 3*a -1);

																																																																																														        de=30;
																																																																																																																																																														        if(!(k1&1))
																																																																																																																																																														        {
																																																																																																																																																														                k1=k1/2;
																																																																																																																																																														                de=de/2;
																																																																																																																																																														        }
																																																																																																																																																														        else if(!(k2&1))
																																																																																																																																																														        {
																																																																																																																																																														                k2=k2/2;
																																																																																																																																																														                de=de/2;
																																																																																																																																																														        }

																																																																																																																																																														        if(((k1/3)*3)==k1)
																																																																																																																																																														        {
																																																																																																																																																														                k1=k1/3;
																																																																																																																																																														                de=de/3;
																																																																																																																																																														        }
																																																																																																																																																														        /*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																																																																																														        else if(((k2/3)*3)==k2)
																																																																																																																																																														        {
																																																																																																																																																														                k2=k2/3;
																																																																																																																																																														                de=de/3;
																																																																																																																																																														        }
																																																																																																																																																														        else if((((k3/3)*3)==k3))
																																																																																																																																																														        {
																																																																																																																																																														                k3=k3/3;
																																																																																																																																																														                de=de/3;
																																																																																																																																																														        }

																																																																																														        if(((k1/5)*5)==k1)
																																																																																														        {
																																																																																														                k1=k1/5;
																																																																																														                de=de/5;
																																																																																														        }
																																																																																														        else if(((k2/5)*5)==k2)
																																																																																														        {
																																																																																														                k2=k2/5;
																																																																																														                de=de/5;
																																																																																														        }
																																																																																														        else if(((k3/5)*5)==k3)
																																																																																														        {
																																																																																														                k3=k3/5;
																																																																																														                de=de/5;
																																																																																														        }
																																																																																														/*This article is about the sexes that occur in sexually reproducing organisms. For other uses, see Sex (disambiguation).
Page semi-protected

The male gamete (sperm) fertilizing the female gamete (ovum)
Organisms of many species are specialized into male and female varieties, each known as a sex.[1] Sexual reproduction involves the combining and mixing of genetic traits: specialized cells known as gametes combine to form offspring that inherit traits from each parent. Gametes can be identical in form and function (known as isogamy), but in many cases an asymmetry has evolved such that two sex-specific types of gametes (heterogametes) exist (known as anisogamy). By definition, male gametes are small, motile, and optimized to transport their genetic information over a distance, while female gametes are large, non-motile and contain the nutrients necessary for the early development of the young organism. Among humans and other mammals, males typically carry XY chromosomes, whereas females typically carry XX chromosomes, which are a part of the XY sex-determination system.

The gametes produced by an organism determine its sex: males produce male gametes (spermatozoa, or sperm, in animals; pollen in plants) while females produce female gametes (ova, or egg cells); individual organisms which produce both male and female gametes are termed hermaphroditic. Frequently, physical differences are associated w*/
																																																																																																																													        if(k1>m)
																																																																																																																													                k1=k1%m;
																																																																																																																													        p=(k1)*(((k2)*(k3))%m)*((k4/de)%m);
																																																																																																																													        p=p%m;
																																																																																																																													        a=b;


																																																																																																																													        k1=a;
																																																																																																																													        k2=a+1;
																																																																																																																													        k3=2*a+1;

																																																																																																																													        k4=((3*a)*(a) + 3*a -1);


																																																																																																																													        de=30;

																																																																																																																													        if(!(k1&1))
																																																																																														        {
																																																																																														                k1=k1/2;
																																																																																														                de=de/2;
																																																																																														        }
																																																																																														        else if(!(k2&1))
																																																																																														        {
																																																																																														                k2=k2/2;
																																																																																														                de=de/2;
																																																																																														        }

																																																																																														        if(((k1/3)*3)==k1)
																																																																																														        {
																																																																																														                k1=k1/3;
																																																																																														                de=de/3;
																																																																																														        }
																																																																																														        else if(((k2/3)*3)==k2)
																																																																																														        {
																																																																																														                k2=k2/3;
																																																																																														                de=de/3;
																																																																																														        }
																																																																																														        else if((((k3/3)*3)==k3))
																																																																																														        {
																																																																																														                k3=k3/3;
																																																																																														                de=de/3;
																																																																																														        }

																																																																																														        if(((k1/5)*5)==k1)
																																																																																														        {
																																																																																														                k1=k1/5;
																																																																																														                de=de/5;
																																																																																														        }
																																																																																														        else if(((k2/5)*5)==k2)
																																																																																														        {
																																																																																														                k2=k2/5;
																																																																																														                de=de/5;
																																																																																														        }
																																																																																														        else if(((k3/5)*5)==k3)
																																																																																														        {
																																																																																														                k3=k3/5;
																																																																																														                de=de/5;
																																																																																														        }

																																																																																														        if(k1>m)
																																																																																														                k1=k1%m;
																																																																																														       r=(k1)*(((k2)*(k3))%m)*((k4/de)%m);
																																																																																														        r=r%m;
																																																																																														        if(p>=r)
																																																																																														                q=p-r;
																																																																																														        else
																																																																																														                q=p-r+m;
																																																																																														        return q;


																																																																																														        }

}
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
int main()
{
        ll i,j,n,m,k,t,p;
        t = read_int();
        while(t--) {
                 n = read_int();
				m = read_int();
                p=0;
                k=sqrt(n);
                for(i=1;i<k+1;i++) {
                	/*
                	Just before going for my first dive. The world down there is so beautiful that u don't feel like leaving it. Only wish is that oxygen cylinder lasts longer. Got my license to be called18 metre open diver. Still waiting to go for the next diving session.
Since sea diving is covered now sky diving remains in my bucket list.*/
                        						 	p=(p + i * seive((n/i) ,(n/(i+1)) ,n ,m))%m;
                        if(i!=(n/i)) {
                        	/*An attempted coup took place in South Vietnam before dawn on September 13, 1964. Generals Lâm Van Phát and Duong Van �??c sent dissident units into the capital Saigon to overthrow the ruling military junta led by General Nguy?n Khánh. They captured key points and announced the overthrow of the regime on national radio. In the previous month, Khánh's leadership had became increasingly troubled. He had tried to augment his powers by declaring a state of emergency; this provoked large-scale protests calling for an end to military rule. Fearful of losing power, Khánh began making concessions and promised democracy in the near future. He also removed military officials linked to the discriminatory Catholic rule of the former President Ngô �?ình Di?m, including Phát (Interior Minister) and �??c (IV Corps commander), who responded with a coup. With American help, Khánh rallied support and the coup collapsed the next morning without casualties. Despite Khánh's survival, the historian George McTurnan Kahin has described the coup as the start of Khánh's ultimate political decline. His relations with America became increasingly strained and he was deposed in February 1965 with US connivance*/
                                ll te=(n/i);

                                p=(p + (n/i)*seive((n/te),(n/(te+1)),n,m))%m;
                        }
            	}
            	printf("%lld\n",p);
        }
}
