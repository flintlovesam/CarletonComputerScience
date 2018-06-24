male(sammy).
male(jonny).
male(bob).
male(jean).
male(ben).
female(pepi).
female(esther).
female(eliana).
female(rebecca).
father(bob, eliana).
father(bob, sammy).
father(bob, jonny).
father(jean, rebecca).
father(jean, esther).
father(jean, ben).
mother(rebecca, eliana).
mother(rebecca, sammy).
mother(rebecca, jonny).
mother(pepi,rebecca).
mother(pepi,esther).
mother(pepi,ben).
married(rebecca,bob).
married(jean,pepi).


is_mother(X) :- parent(X,_), female(X).
is_father(X) :- parent(X,_), male(X).

different(X,Y) :- \+ (X == Y).

parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).

grandfather(X, Y) :- father(X, Z), parent(Z, Y) , male(X). /* Rule  3 */
grandmother(X, Y) :- female(X), mother(X, Z), parent(Z, Y). /* Rule  4 */

brother(X,Y) :- parent(Z,X), parent(Z,Y), male(X).
sister(X,Y) :- parent(Z,X), parent(Z,Y), female(X).

ancestor(X,Y) :- parent(X, Y) ; grandfather(X, Y) ; grandmother(X, Y).

aunt(X,Y) :- female(X),sister(X,Mom),parent(Mom,Y).
aunt(X,Y) :- female(X),sister(X,Dad),parent(Dad,Y).
uncle(X,Y) :- brother(X,Par),parent(Par,Y).
