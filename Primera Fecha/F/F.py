[s, d] = input().split()
s = int(s)

d_sec = int(d.split('.')[0])
d_mil = int(d.split('.')[1])

for x in range(s):
    i = input()
    print(i)
    timeline = input()
    content = []
    n = input()
    while n.strip() != '':
        content.append(n)
        try:
            n = input()
        except:
            break
    
    [start, end] = timeline.split(' --> ')
    [s_hr, s_min, s_secc] = start.split(':')
    s_hr = int(s_hr)
    s_min = int(s_min)
    s_sec = int(s_secc.split(',')[0])
    s_mil = int(s_secc.split(',')[1])

    s_mil += d_mil
    if(s_mil > 999):
        s_sec += 1
        s_mil -= 1000
    s_sec += d_sec
    if(s_sec > 60):
        s_min += 1
        s_sec -+ 60
    if(s_min > 60):
        s_hr += 1
        s_min -+ 60

    [e_hr, e_min, e_secc] = end.split(':')
    e_hr = int(e_hr)
    e_min = int(e_min)
    e_sec = int(e_secc.split(',')[0])
    e_mil = int(e_secc.split(',')[1])

    e_mil += d_mil
    if(e_mil > 999):
        e_sec += 1
        e_mil -= 1000
    e_sec += d_sec
    if(e_sec > 60):
        e_min += 1
        e_sec -+ 60
    if(e_min > 60):
        e_hr += 1
        e_min -+ 60

    st = str(s_hr).zfill(2) + ':' + str(s_min).zfill(2) + ':' + str(s_sec).zfill(2) + ',' + str(s_mil).zfill(3)
    en = str(e_hr).zfill(2) + ':' + str(e_min).zfill(2) + ':' + str(e_sec).zfill(2) + ',' + str(e_mil).zfill(3)
    print(st + ' --> ' + en)
    for el in content:
        print(el)
    if int(i) != s:
        print()