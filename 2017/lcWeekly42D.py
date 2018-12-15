class Solution(object):
    def replaceWords(self, dict, sentence):
        words = sentence.split(' ')
        maxi=0
        i=0
        while i<len(dict):
            maxi=max(maxi,len(dict[i]))
            i=i+1
        maxi=maxi+1
        i=0
        ansS = ''
        while i<len(words):
            s=words[i]
            j=0
            c=''
            cnt=0
            while j<len(s) and j<maxi:
                c=c+s[j]
                if dict.count(c)>0:
                    ansS=ansS+c
                    cnt=1
                    break
                j=j+1
            if cnt==0:
                ansS=ansS+s
            if i!=len(words)-1:
                ansS=ansS+' '
            i=i+1
        
        return ansS
