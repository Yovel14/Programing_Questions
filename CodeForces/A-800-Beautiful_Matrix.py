for row in range(5):
    t = input().find('1')
    if t!=-1:
        RowIndex = row
        ColIndex = t
print(abs(ColIndex-4)//2+abs(RowIndex-2))