function my_func(word)
    local i = 0
    
    return function ()
        i = i+1
        if string.len(word) == 0 then
            return nil
        end
        if i > string.len(word) then
            return my_func(string.sub(word, 1, string.len(word)))
        end
        next = string.sub(word, 0, i)
        return next
    end
end



print("Enter a string")
word = io.read("l")

for sbst in my_func(word) do
    print(sbst)
end
