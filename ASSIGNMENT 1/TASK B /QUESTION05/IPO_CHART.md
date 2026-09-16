# Smart Campus Parking and Access Management System
|INPUT|PROCESSING|OUTPUT|
|---|---|---|
|Number of vehicles, Vehicle type, User category, Parking permit, Emergency vehicle(Y/N)|Validate all values||
| |Parking zone capacities(Zone A = 20 ,Zone B = 40,Zone C = 15)||
||Determine parking eligibility based on:(Vehicle type, User category, Permit status,Emergency status)||
||Check available capacity in the appropriate zone||
||Apply alternative-zone rules where applicable||
||Assign required parking spaces:(Car = 1 space, Bike = 1 space, Van = 2 spaces)||
||Update occupied and remaining capacity of each zone||
||Count successfully parked cars, bikes, and vans||
||Count rejected vehicles||
||Display rejection reason when a vehicle is rejected||
||After processing all vehicles:<br>-  Calculate total processed vehicles.<br>-  Calculate total accepted and rejected vehicles.<br>-  Determine final occupancy of each zone.<br>-  Determine remaining capacity of each zone.<br>-  Find the zone with the highest occupancy.<br>-  Check whether the entire campus parking facility is full<br>||
|||- Assigned parking zone for each accepted vehicle<br>-  Remaining capacity of the assigned zone<br>- Rejection reason for each rejected vehicle<br>- Total vehicles processed<br>- Total accepted vehicles<br>- Total rejected vehicles<br>- Successfully parked cars<br>- Successfully parked bikes<br>- Successfully parked vans<br>- Final occupancy of Zone A<br>- Final occupancy of Zone B<br>- Final occupancy of Zone C<br>- Remaining capacity of Zone A<br>- Remaining capacity of Zone B <br>- Remaining capacity of Zone C<br>- Zone with the highest occupancy<br>- Whether the entire campus parking facility is full|
