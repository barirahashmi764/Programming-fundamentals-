# Smart Campus Parking and Access Management System
|DATA REQUIRED |PROCESSING |RESULT |ALTERNATIVE |
|---|---|---|---|
|Number of vehicles |Loop for N vehicles|||
|Vehicle type:<br>- C = Car<br>- B = Bike<br>- V = Van|validate|||
|User category:<br>- F = Faculty<br>- S = Student<br>- G = Visitor/Guest|validate|||
|Parking permit:<br>- Y = Valid<br>- N = Invalid|validate|||
|Emergency vehicle:<br>- Y = Yes<br>- N = No|validate|||
||If permit is invalid, check whether vehicle is an emergency vehicle|||
||Determine parking eligibility based on:<br>- Vehicle type<br>- User category<br>- Permit status<br>- Emergency status|||
||Check available capacity in the appropriate zone|||
||Apply alternative-zone rules where applicable|||
||Assign required parking spaces|||
||Update occupied and remaining capacity of each zone|||
||Count successfully parked cars, bikes, and vans|||
||Count rejected vehicles|Display rejection reason when a vehicle is rejected||
|||||
||After processing all vehicles: <br>- Calculate total processed vehicles<br>- Calculate total accepted and rejected vehicles<br>- Determine final occupancy of each zone<br>- Determine remaining capacity of each zone<br>- Find the zone with the highest occupancy<br>- Check whether the entire campus parking facility is full|||
|||- Assigned parking zone for each accepted vehicle<br>- Remaining capacity of the assigned zone<br>- Rejection reason for each rejected vehicle<br>- Total vehicles processed<br>- Total accepted vehicles<br>- Total rejected vehicles<br>- Successfully parked cars<br>- Successfully parked bikes<br>- Successfully parked vans Final occupancy of Zone A<br>- Final occupancy of Zone B<br>- Final occupancy of Zone C<br>- Remaining capacity of Zone A<br>- Remaining capacity of Zone B<br>- Remaining capacity of Zone C<br>- Zone with the highest occupancy<br>- Whether the entire campus parking facility is full||
