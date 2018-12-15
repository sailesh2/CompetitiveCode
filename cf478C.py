x=raw_input().split(' ')
r=int(x[0])
g=int(x[1])
b=int(x[2])
sm=0
if r+g+b>=3 and ((r!=0 and g!=0) or (r!=0 and b!=0) or (b!=0 and g!=0)):
    if r==0 or g==0 or b==0:
        if g==0:
            if r<b:
                if b>2*r:
                    sm=r
                    b=b-r
                else:
                    sm=b/2
                    b=b-sm*2
            else:
                if r>2*b:
                    sm=b
                    r=r-b
                else:
                    sm=r/2
                    r=r-sm*2
        elif b==0:
            if r<g:
                if g>2*r:
                    sm=r
                    g=g-r
                else:
                    sm=g/2
                    g=g-sm*2
            else:
                if r>2*g:
                    sm=g
                    r=r-g
                else:
                    sm=r/2
                    r=r-sm*2
        else:
            if g<b:
                if b>2*g:
                    sm=g
                    b=b-g
                else:
                    sm=b/2
                    b=b-sm*2
            else:
                if g>2*b:
                    sm=b
                    g=g-b
                else:
                    sm=g/2
                    g=g-sm*2
    else:
        if r<=b and r<=g:
            sm=r
            g=g-r
            b=b-r
            if g+b>=3 and g!=0 and b!=0:
                if g<=b:
                    if b>2*g:
                        sm=sm+g
                    else:
                        sm=sm+b/2
                else:
                    if g>2*b:
                        sm=sm+b
                    else:
                        sm=sm+g/2
        elif g<=r and g<=b:
            sm=g
            r=r-g
            b=b-g
            if r+b>=3 and r!=0 and b!=0:
                if r<=b:
                    if b>2*r:
                        sm=sm+r
                    else:
                        sm=sm+b/2
                else:
                    if r>2*b:
                        sm=sm+b
                    else:
                        sm=sm+r/2
        else:
            sm=b
            g=g-b
            r=r-b
            if r+g>=3 and r!=0 and b!=0:
                if r<=g:
                    if g>2*r:
                        sm=sm+r
                    else:
                        sm=sm+g/2
                else:
                    if r>2*g:
                        sm=sm+g
                    else:
                        sm=sm+r/2
print sm
