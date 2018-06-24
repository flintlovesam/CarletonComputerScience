actor(jonny, depp, gender(male)).
actor(bruce, willis, gender(male)).
actor(glenn, close, gender(female)).
actor(orlando, bloom, gender(male)).
actor(jennifer, lawrence, gender(female)).
actor(sean, bean, gender(male)).
actor(angelina, jolie, gender(female)).
actor(keira, knightley, gender(female)).
actor(benedict, cumberbatch, gender(male)).
actor(james,mcavoy, gender(male)).
actor(robin, williams, gender(male)).
actor(emilia, clarke, gender(female)).
actor(ryan, reynolds, gender(male)).
actor(chris, pratt, gender(male)).
actor(karen, gillan, gender(female)).

movie(year(2003), title([pirates,of,the,carribean]), cast([actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)])).
movie(year(2014), title([guardians, of, the, galaxy]), cast([actor(chris, pratt), actor(karen,gillan) ])).
movie(year(1988), title([die,hard]), cast([actor(bruce, willis)])).
movie(year(2001), title([lord,of,the,rings]), cast([actor(orlando, bloom), actor(sean, bean)])).
movie(year(2016), title([xmen, apocalypse]), cast([actor(jennifer,lawrence), actor(james, mcavoy)])).
movie(year(2014), title([the,imitation,game]), cast([actor(benedict, cumberbatch), actor(keira, knightley)])).
movie(year(2012), title([the,hunger,games]), cast([actor(jennifer,lawrence)])).
movie(year(2016), title([deadpool]), cast([actor(ryan, reynolds)])).

/*
split(List,Pivot, L1, L2)
*/



split([],Pivot,[],[]).

split([H|T],Pivot,[H|L1],L2):-
  H=<Pivot, split(T,Pivot,L1,L2).

split([H|T],Pivot,L1,[H|L2]):-
  H>Pivot, split(T,Pivot,L1,L2).


gradeMap([],[]).
gradeMap([H|T],[a|R]):-
  H>=81,H=<100,
  gradeMap(T,R).
gradeMap([H|T],[b|R]):-
  H>=71,
  H=<80,
  gradeMap(T,R).
gradeMap([H|T],[c|R]):-
  H>=61,
  H=<70,
  gradeMap(T,R).
gradeMap([H|T],[d|R]):-
  H>=51,
  H=<60,
  gradeMap(T,R).
gradeMap([H|T],[f|R]):-
  H>=0,
  H=<50,
  gradeMap(T,R).


  nextto(X, Y, [X,Y|_]).
nextto(X, Y, [_|Tail]) :-
    nextto(X, Y, Tail).


    myappend([],L,L).
    myappend([H|T],L2,[H|L3])  :-  myappend(T,L2,L3).



    flatten2([], []) :- !.
    flatten2([L|Ls], FlatL) :-
        !,
        flatten2(L, NewL),
        flatten2(Ls, NewLs),
        append(NewL, NewLs, FlatL).
    flatten2(L, [L]).
