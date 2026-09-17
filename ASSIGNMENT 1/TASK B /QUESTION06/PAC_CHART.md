# Smart EV Charging and Parking Management System
|DATA REQUIRED|PROCESSING|RESULT|ALTERNATIVE SOLUTION|
|---|---|---|---|
| Vehicle type (E/H) | Check whether charging station is available and whether the vehicle qualifies for charging | Charging availability / qualification message | If station unavailable → Hybrid: Parking only; otherwise → No charging slot available |
| Current battery level (%) | Check whether the vehicle is eligible for EV charging | Vehicle qualifies / does not qualify | E → qualifies; H with battery below 40% → qualifies |
| Required charging level (%) | Calculate Required Charging = Required Level − Current Battery Level | Required charging amount | If required level ≤ current battery → No charging required |
| Battery level + Required charging level | Check emergency charging conditions | Charging priority | Battery ≤ 15% AND required level ≥ 80% → Emergency Charging Priority |
| Disabled-person priority + Membership + Battery level | Check priority customer conditions | Priority Charging / Normal Charging | Disabled priority = Y OR Member = Y AND battery ≤ 30% → Priority Charging; otherwise → Normal Charging |
| Current time | Determine peak or off-peak period | Peak / Off-peak status | Before 5 PM or after 10 PM → Off-peak; 5 PM–10 PM → Peak |
| Membership + Charging priority | Apply charging discount | Charging discount | Off-peak member → 20% discount; Peak → 10% discount; Emergency → No membership discount |
| Required charging amount + Time | Calculate charging cost | Charging cost | Off-peak → Rs. 35 per unit; Peak → Rs. 50 per unit |
| Parking duration | Determine parking charge | Parking cost | Up to 2 hours → Rs. 200; More than 2 up to 5 hours → Rs. 400; More than 5 hours → Rs. 700 |
| Membership | Apply parking discount | Parking discount | Member → 20% parking discount |
| Disabled-person priority | Check free parking condition | Free parking / Parking cost | Disabled priority = Y → Free parking |
| Parking duration | Check long-stay condition | Parking warning | More than 8 hours → Long-stay warning; otherwise → Standard parking duration |
| Charging cost + Parking cost + Discounts | Calculate final payable amount | Final payable amount | Final amount = Charging cost after discount + Parking cost after discount |
