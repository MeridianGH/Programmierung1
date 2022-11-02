## Aufgabe 1

a)\
Seien `int x` und `unsigned int n` zwei Integer. Erläutern Sie folgenden Ausdruck:
```c
(x << n) | (x >> (sizeof(int)*8 - n)) & ~(-1 << n).
```
---

`x` und `n`:
- `int x` ist eine ganze Zahl, d.h. auch negativ.
- `unsigned int n` ist eine positive, ganze Zahl.


Operator Precedence:
- `bitwise not: ~`
- `bitwise shift: << / >>`
- `bitwise and: &`
- `bitwise or: |`

Ablauf der Expression:
- `x` wird bitweise um `n` nach links verschoben
- `x` wird bitweise um `sizeof(int) * 8 - n` nach rechts verschoben
- `-1` wird bitweise um `n` nach links verschoben und dann bitweise negiert.
- Die Verschiebung von `x` nach rechts wird mit der Verschiebung von `-1` bitweise "verUNDet".
- Die Verschiebung von `x` nach links wird mit dem Ergebnis der AND-Operation bitweise "verODERt".