package week3.polynom;

import java.util.ArrayList;

class Polynom {

    private ArrayList<Term> terms;

    public Polynom() {
        terms = new ArrayList<>();
    }

    /**
     * TODO: Implement a Copy constructor
     * @param other
     */
    public Polynom(Polynom other)
    {
        terms = new ArrayList<>();
        for (int t = 0; t < other.terms.size(); t++) {
            Term term = other.terms.get(t);
            Term copy = new Term(term);
            terms.add(copy);
        }
    }

    public void addTerm(Term t)
    {
        if (t.getCoeff()==0)
            return;

        if (terms.isEmpty())
        {
            terms.add(t);
            return;
        }

        int i=0;

        for (;  i< terms.size() &&  terms.get(i).getDegree()> t.getDegree() ; i++);

        if (i>=terms.size() ||  !terms.get(i).add(t))
            terms.add(i,t);

        if (terms.get(i).getCoeff() ==0)
            terms.remove(i);

    }

    /**
     * TODO: Implement add method that adds another polynom to this polynom
     * @return
     */
    public void add(Polynom other)
    {
        // * your code here
        for (int t = 0; t < other.termCount(); t++) {
            addTerm( new Term(other.terms.get(t)));
        }

    }

    private int termCount() {
        return terms.size();
    }

    /**
     * TODO: Implement multiply method that multiplies this polynom with given term
     * @param term
     */
    public void multiply(Term term)
    {
        for (int t = 0; t < terms.size(); t++) {
            terms.get(t).multiply(term);
        }

    }




    /**
     * TODO: Implement multiply method that multiplies this polynom with other polynom
     * @param other
     */
    public void multiply(Polynom other)
    {
        Polynom result = new Polynom();

        for (int t = 0; t < other.termCount(); t++) {
            Polynom p = new Polynom(this);
            p.multiply(other.terms.get(t));
            result.add(p);
        }
        terms = result.terms;

    }




    public String toString()
    {
        String st ="";

        for (int t = 0; t < terms.size(); t++) {
            if (t>0 && terms.get(t).getCoeff()>0)
                st+="+";
            st += terms.get(t);
        }
        return st;
    }

    public static void mainold(String[] args) {
        Polynom p  = new Polynom();

        p.addTerm(new Term(2,3));
        p.addTerm(new Term(-3,4));
        p.addTerm(new Term(3,4));
        p.addTerm(new Term(-3,0));

        System.out.println(p);

        Polynom p2 = new Polynom(p);
        System.out.println(p2);

        p2.addTerm(new Term(8,5));


        System.out.println(p2);
        System.out.println(p);

        p2.add(p);

        System.out.println(p2);

        p2.multiply(new Term(-1,2));

        System.out.println(p2);


    }

    public static void main(String[] args) {
        Polynom p  = new Polynom();

        p.addTerm(new Term(1,2));
        p.addTerm(new Term(2,1));

        Polynom p2 = new Polynom();

        p2.addTerm(new Term(3,3));
        p2.addTerm(new Term(2,0));

        System.out.println(p);
        System.out.println(p2);
        p.multiply(p2);


        System.out.println(p);
    }
}
