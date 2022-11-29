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
    local cr = coroutine.create(in_order)
    return function()
            local status, el = coroutine.resume(cr, bst)
            if status then
                return el
            end
            return nil
        end
    end



-- TODO #1: test the coroutine manually
cr  = coroutine.create(in_order)
print(coroutine.resume(cr, bst))
print(coroutine.resume(cr, bst))

-- TODO #3: test your iterator 

