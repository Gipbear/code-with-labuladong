
def longPre(words):
    res = ""
    ind = 0
    flag = False
    while ind < len(words[0]):
        tmp = words[0][ind]
        for word in words:
            if word[ind] != tmp:
                flag = True
                break
        if flag:
            break
        else:
            res += tmp
            ind += 1
    return res


if __name__ == '__main__':
    words = input().split(',')
    res = longPre(words)
    print(res)

