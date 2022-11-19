function in_order(current) 
    if current then
        if current.left then
            in_order(current.left)
        end
        coroutine.yield(current.value)
        if current.right then
            in_order(current.right)
        end
    end
end

bst = {
    value = 10, 
    left = {
        value = 5, 
        left = {
            value = 1, 
            left = nil, 
            right = nil
        }, 
        right = {
            value = 7, 
            left = nil, 
            right = nil
        }
    }, 
    right = { 
        value = 15, 
        left = {
            value = 12, 
            left = nil, 
            right = nil
        }, 
        right = {
            value = 17, 
            left = nil, 
            right = nil
        }
    }
}

-- TODO #2: write an iterator using in_order
function my_iterator(bst)
    local co = coroutine.create(function (bst)
        return in_order(bst)
    end)

    function ()
    
    end
        
    end

end

-- TODO #1: test the coroutine manually
cc  = coroutine.create(in_order)
print(coroutine.resume(cc, bst))
print(coroutine.resume(cc, bst))

-- TODO #3: test your iterator 