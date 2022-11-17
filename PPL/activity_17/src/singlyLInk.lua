function list_it(list)
    return function ()
        if list then
        local value = list.value
        list = list.next
        return value
        end
    end
end



list = nil
list = { next = list, value =5}
list = { next = list, value =6}
list = { next = list, value =8}
list = { next = list, value =13}
list = { next = list, value =-5}
list = { next = list, value =2022}

for el in list_it(list) do
    print(el)
end
for el in list_it(list) do
    print(el)
end