Turning Santa Paravia into C++ Code with Objects

Major Abstractions for Santa Paravia
1. Player
	The "Me" object in the code contains the data that has to do with the players resources.
	ex. (Me->Treasury, Me->GrainReserve)
	- ShowStats (line 899)
	- ImDead (line 915)

2. Grain
	Grain is associated with a lot of functions in the game
	- SellGrain (line 627)
	- ReleaseGrain (line 477)
	- PrintGrain (464)
	
3. Land
	Land is similar to grain, but with fewer functions
	- SellLand (line 643)
	- BuyLand (line 282)
	
4. Serfs
	- SerfsProcreating (line 671)
	- SerfsDecomposing (line 659)
	
There are a lot of items that corresspond to the player. Some of these should be member variables.
But should all of them be?
ex. (line 179 to line 214)

Perhaps there will be a variety of objects, and each player will have their own instance of that object.


