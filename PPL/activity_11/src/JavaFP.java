/*
 * CS3210 - Principles of Programming Languages - Fall 2022
 * Instructor: Thyago Mota
 * Description: Activity 11 - Functional Programming in Java
 */

import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Stream;

public class JavaFP {

    // TODO: implement a filter-like function in Java
    static List<Integer> filter(List<Integer> in, Predicate<Integer> pred) {
        List<Integer> out = new LinkedList<>();
        for (Integer el: in) {
            if(pred.test(el)){
                out.add(el);
            }
        }
        return out;
    }

    public static void main(String[] args) {
        // creates a dummy linkedlist 1-10
        List<Integer> in = new LinkedList<>();
        for (int i = 1; i <= 10; i++)
            in.add(i);

        // TODO: use filter to create a linkedlist called out (from in) but with only in's even numbers
        // define predicate with an override
        List<Integer> out = filter(in,
                new Predicate<Integer>() {
                    @java.lang.Override
                    public boolean test(Integer value) {
                        return value % 2 == 0;
                    }
                });
        System.out.println(out);

        // TODO: do the same but now using lambda function syntax to define predicate
        List<Integer> out2 = filter(in, val -> val %2 ==0);
        System.out.println(out2);

        // TODO: do all of the above but now using the stream package
        Stream<Integer> inS = in.stream();
        //Stream<Integer> outs = inS.filter(val -> val % 2==0);
        //outs.forEach( val -> System.out.println(val));

        // TODO: use stream's reduce to compute a simple summation of in

        Optional<Integer> sum = inS.reduce((val1 , val2) -> val1 + val2);
        Stream<Integer> sumStream = sum.stream();
        sumStream.forEach(val -> System.out.println(val));


    }
}
