|INPUT|PROCESSING|OUTPUT|
|---|---|---|
|price, quantity, tax(%),discount(%)|subtotal=0,discount=0,finalprice=0||
||check validation for input | print invalid(if condition satisfy)|
||s=q*p||
||a=s-(s*d)/100||
||f=a+(a*t)/100||
|||subtotal,disount,finalprice|
