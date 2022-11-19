function producer()
    while true do
        coroutine.yield(
            io.read()
        )    
    end
end

function consumer(prd)
    status = true
    while status do
        local status, value = coroutine.resume(prd)
        print(value)
    end
end

prd = coroutine.create(producer)
cns = coroutine.create(consumer)
coroutine.resume(cns, prd)