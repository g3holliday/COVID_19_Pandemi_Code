Python 2.7.18 (v2.7.18:8d21aa21f2, Apr 19 2020, 20:48:48) 
[GCC 4.2.1 Compatible Apple LLVM 6.0 (clang-600.0.57)] on darwin
Type "help", "copyright", "credits" or "license()" for more information.
>>> Now = 0
Left = 0
Right = 0

def on_button_pressed_ab():
    global Now
    Now = input.running_time()
    basic.show_number(Now)
input.on_button_pressed(Button.AB, on_button_pressed_ab)

def on_forever():
    global Left, Right
    if input.rotation(Rotation.ROLL) < -10:
        basic.show_leds("""
            # . . . .
            # . . . .
            # . . . .
            # # # # .
            . . . . .
            """)
        Left += 1
        basic.show_number(Left)
    if input.rotation(Rotation.ROLL) > 10:
        basic.show_leds("""
            # # # . .
            # . # . .
            # # # . .
            # . # . .
            # . . # .
            """)
        Right += 1
        basic.show_number(Right)
    if abs(input.rotation(Rotation.ROLL)) < 10:
        basic.clear_screen()
    if input.button_is_pressed(Button.A):
        basic.show_number(Right)
    if input.button_is_pressed(Button.B):
        basic.show_number(Left)
basic.forever(on_forever)
