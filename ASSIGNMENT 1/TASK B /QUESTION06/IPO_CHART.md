# Smart EV Charging and Parking Management System
|INPUT|PROCESSING|OUTPUT|
|---|---|---|
|-  Vehicle type(E:electric,H:hybrid)<br>-  Current battery level<br>-  Required charging level<br>-  Expected parking duration<br>-  Current time<br>-  Parking membership<br>-  Disabled person priority<br>-  Charging station availability|||
||Validate the entered vehicle type and other input values||
||Check charging station availibilty||
||If unavailable: If vehicle is hybrid |display "Charging unavailable – Parking only|
||Otherwise, display |"No charging slot available."|
||If the station is available:<br>-  Check whether the vehicle qualifies for EV charging.<br>-  Electric vehicles can use the charging station.<br>-  Hybrid vehicles can use the charging station only if battery level is below 40%.||
||Calculate required charging:<br>Required Charging = Required Charging Level − Current Battery Level||
||If required charging level is less than or equal to current battery level |display "No charging required."|
||Assign charging priority:<br>-  Priority 1: Emergency Charging if battery ≤ 15% and required charging level ≥ 80%.<br>-  Priority 2: Priority Charging if disabled status is Y, or membership is Y and battery ≤ 30%.<br>-  Priority 3: Normal Charging otherwise.||
||Determine peak/off-peak status based on current time.||
||Calculate charging cost according to the applicable charging rate.||
||Apply membership discount during off-peak or peak hours where applicable.||
||Do not apply membership discount to Emergency Charging Priority.||
||Calculate parking cost according to parking duration:<br>- Up to 2 hours = Rs. 200<br>- More than 2 and up to 5 hours = Rs. 400<br>- More than 5 hours = Rs. 700||
||Apply parking discount:<br>-  Member = 20% parking discount.<br>-  Disabled-person priority = free parking.||
||Calculate final payable amount: <br>Final Amount = Charging Cost + Parking Cost − Discount||
||Check parking duration:<br>- More than 8 hours = Long-stay warning.<br>- Otherwise = Standard parking duration.||
|||- Vehicle type <br>- Current battery percentage<br>- Required charging percentage<br>- Charging priority<br>- Peak/off-peak status<br>- Charging cost<br>- Parking cost<br>- Discount<br>- Final payable amount<br>- Appropriate warning/message|
