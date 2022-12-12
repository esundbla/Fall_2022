-- CS3210 - Principles of Programming Languages - Fall 2022
-- Instructor: Thyago Mota
-- Description: elections simulation with coroutines
-- Student Name(s): Erik Sundblad

PROPOSALS = 3
VOTERS    = 1000000
time = os.clock()

-- TODO #1: create a ballot and randomly assign 0 (no) or 1 (yes) to each proposal; then begin a timed loop of up to 10s (also random); at each iteration the function should yield; at the end of the loop, insert the ballot in the (given) ballot_box
function vote()
    local ballot  = {}
    for i=1, PROPOSALS do
        ballot[i] = math.random(0,1)
       
    end
    for j=1, math.random(1,10) do
        coroutine.yield()
    end
    table.insert(ballot_box, ballot)
end

-- TODO #2: return a tally of the results as a percent of 1s (yes) that was given to each proposal
function tally_results() 
    local result = {0,0,0}
    for j=1, VOTERS do
        for i=1, PROPOSALS do
            result[i] = result[i] + ballot_box[j][i]
        end
    end
    for i=1, PROPOSALS do
        result[i] = (result[i] / VOTERS) * 100
    end
    return result
end
-- TODO #3: time when the election started


-- TODO #4: create a ballot_box
ballot_box = {}
-- TODO #4 create an array of "vote" coroutines
local voting = {}
for i=1, VOTERS do
    voting[i] = coroutine.create(vote)
end
-- TODO #5: schedule the coroutines so each has a fair chance of running until completion
local run = true
while(run) do
    run = false
    for i=1, VOTERS do
        if coroutine.resume(voting[i]) then
            run = true
        end
    end
end
-- TODO #6: display the results

local result = tally_results()
print("Election Results:\n1", result[1], "\n2", result[2], "\n3", result[3])
-- TODO #7: show how long the election took in seconds
print("Time elapsed:", os.clock() - time, "seconds!")