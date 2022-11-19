function say_hi(n)
    for i = 1, n do
        coroutine.yield(i, "hi!")
    end
end

cr = coroutine.create(
    say_hi
)
-- having yield returns values
-- note that the last return is the function's final return
while coroutine.status(cr) ~= "dead" do
    print(coroutine.resume(cr, 10))
end