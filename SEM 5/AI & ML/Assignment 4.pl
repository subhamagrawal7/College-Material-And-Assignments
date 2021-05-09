% state(Monkey location in the room, Monkey onbox/onfloor, box location, has/hasnot banana)

% legal actions

% monkey and box are in the middle and the monkey is on the box
move(state(middle,onbox,middle,hasnot), % grab banana 
	 grab,
	state(middle,onbox,middle,has)).
% horizontal positions of monkey and box are same and denoted by 'P'
move(state(P,onfloor,P,H),  % climb box
	 climb,
	 state(P,onbox,P,H)).
% Vertical positions remains same denoted by 'H'
move(state(P1,onfloor,P1,H), % push box from L1 to L2
	 push(P1,P2),
	 state(P2,onfloor,P2,H)).
% 
move(state(P1,onfloor,B,H),  % walk from L1 to L2
	 walk(P1,P2),
	 state(P2,onfloor,B,H)).

% canget(State): monkey can get Banana in State

canget(state(_,_,_,has)).    % Monkey already has it, goal state
canget(State1) :-			 % If not a goal state then we need to do something(grab,climb,push,walk)
		move(State1,_,State2),
		canget(State2).		 % canget from State2


%?- canget(state(atdoor,onfloor,atwindow,hasnot)).
