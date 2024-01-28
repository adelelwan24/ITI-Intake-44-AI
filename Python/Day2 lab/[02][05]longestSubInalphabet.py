def longestSubInAlphabet(text : str) -> str:
    start = 0
    longest = 1
    res = (start, longest)  # (start, len)
    for i in range( len(text) - 1):
        if text[i] > text[i+1]:
            if longest > res[1]:
                res = (start, longest)
            start = i + 1
            longest = 1
        else:
            longest +=1
    else:
        if longest > res[1]:
                res = (start, longest)
    
    return text[res[0]:res[0] + res[1]]

print( longestSubInAlphabet("abdulrahman"))
print( longestSubInAlphabet("abcdaghabcdef"))