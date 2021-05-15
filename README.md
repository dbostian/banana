# Banana
## A 3d Printed Macropad

![example](https://i.imgur.com/2F6gi57.jpg)

![example](https://i.imgur.com/GmIcL3O.jpg)

## Intro
A 3d-printed macropad for the discerning ergonomic mechanical keyboard enthusiast.

## FAQ
**Q) Why?**

A) It ap-peeled to my sense of humor.

**Q) Is this really ergonomic?**

A) The banana is perfectly shaped to fit the human hand. Checkmate, ortho gang.

**Q) My alphabet of choice has more than 8 characters. How do you expect me to type on this?**

A) Print a bunch!

**Q) Where did you learn your soldering skills?**

A) Sundae school!

**Q) Which key is your favorite?**

A) The mon-key!

**Q) I hate everything about this.**

A) Stop, you're hurting my peelings.



## Project Structure
**/stls** - STL files for 3d Printing

**/arduino** - Sample Arduino sketch for firmware

## Construction

### Printed Parts
- [ ] 1x split_a.stl - [https://github.com/dbostian/banana/blob/main/stls/split_a.stl](https://github.com/dbostian/banana/blob/main/stls/split_a.stl)
- [ ] 1x split_b.stl - [https://github.com/dbostian/banana/blob/main/stls/split_b.stl](https://github.com/dbostian/banana/blob/main/stls/split_b.stl)

### Hardware
- [ ] 8x Switches - Cherry MX or compatible.
- [ ] 8x Keycaps
- [ ] 1x Pro Micro
- [ ] 2x M3 x 12mm Socket Cap Machine Screw
- [ ] 2x M3 Heatset Threaded Inserts
- [ ] Sticker (optional)
- [ ] Wire


### Tools / Misc
- [ ] 3d Printer + Filament
- [ ] Soldering Iron + Solder
- [ ] Multimeter
- [ ] Wire Cutters / Strippers / Flush Cutters
- [ ] Hex Drivers

### Printing Notes
Printed in PLA at 0.3 (or finer) layer height. Both halves need support.

### Assembly + Wiring
Install heatset inserts and switches into the top half. There are many ways to wire a macropad. Since this one has only 8 switches, I wired one leg of each directly to an input pin on the Pro Micro. I used pins 10, 16, 14, 15, 18 (A0), 19 (A1), 20 (A2), and 21 (A3). The other leg of each switch is wired to ground. Diodes are not needed in this case.

![example](https://i.imgur.com/YY8CSGe.jpg)


### Firmware
The included Arduino sketch is a starting point for a simple macropad. It can be flashed to your microcontroller with the Arduino IDE - [https://www.arduino.cc/](https://www.arduino.cc/). You'll want to edit this section of the code to send a different strings or keystrokes (see the Arduino Keyboard reference for more details - [https://www.arduino.cc/reference/en/language/functions/usb/keyboard/](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/)):


```
...
if (val != states[i]) {
    if (lastChange[i] < (now - DEBOUNCE_TIME)) {
      states[i] = val;
      if (val == LOW) {
        switch(i) {
          case 0:
            Keyboard.print("Ba");
            break;
          case 1:
            Keyboard.print("na");
            break;
          case 2:
            Keyboard.print("na");
            break;
          case 3:
            Keyboard.print("na");
            break;
          case 4:
            Keyboard.print("na");
            break;
          case 5:
            Keyboard.print("na");
            break;
          case 6:
            Keyboard.print("na");
            break;
          case 7:
            Keyboard.print("na!");
            break;
          default:
            break;
        }
        
      } else {
        // On key up
      }
    }    
  }
...
```

