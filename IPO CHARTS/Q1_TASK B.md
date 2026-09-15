# Hotel Booking System — IPO Chart

| INPUT | PROCESSING | OUTPUT |
|---|---|---|
| N (number of guests) | Set Hotel Total Revenue = 0 | |
| Nights stayed | Repeat for N guests | |
| Season (Peak / Off-Peak) | Determine rate based on season and room type | |
| Room Type (Standard / Deluxe / Suite) | Calculate total = rate × nights | |
| | If nights > 7, calculate 15% discount | |
| | Calculate finalPrice = total − discount | Final price for each guest |
| | Add finalPrice to HotelTotalRevenue | |
| | After all guests are processed | Hotel Total Revenue |
