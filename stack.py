# take input n, m
n = 5
m = 5 # for example
st = Stack()
st.push([1,1,0]) # x, y, direction

ans = [] # contains all paths as a list of points

while len(st) > 0:
    if(st.top()[0] > n or st.top()[1] > m or st.top()[2] > 1):
        st.pop()
        st.top()[2] += 1
        continue
    if(st.top()[0] == n and st.top()[1] == m):
        # found one path, now list it
        st2 = Stack()
        ans.append([])
        while len(st) > 0:
            ans[-1].append([st.top()[0], st.top()[1]])
            st2.push(st.top())
            st.pop()
        ans[-1] = ans[-1][::-1] # reverse it
        while len(st2) > 0: # restore the stack
            st.push(st2.top())
            st2.pop()
        st.pop()
        st.top()[2] += 1
        continue

    if(st.top()[2] == 1):
        st.push([st.top()[0], st.top()[1] + 1, 0]) # go up direction
    else:
        st.push([st.top()[0] + 1, st.top()[1], 0]) # go right direction
        



