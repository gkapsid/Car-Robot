# Car-Robot
Car Robot construction from EDX Berkley EE40LX: Eletronic Interfaces: Bridging the Physical and Digital Worlds

## Files


* sketch_1_4_ard : Simple blink led file
* sketch_2_d_ard : Blink led and serial communication for debugging
* sketch_3_2_ard : Power block the op amp and read the inputs from Wheatstone bridges (see schematics) 
* sketch_3_4_ard : outputs 800 Hz square wave in random burst patterns to test the buzzer.
* sketch_3_6_ard : reads the output of the microphone circuit at P1.5 and decides whether or not to flash on an LED based on the sound level Tests the mic circuit.
* sketch_6_4_ard : creates a PWM signal for motor control
* sketch_7_ard : Final scketch according the proposed flow chart ()

## Circuits and Schematics

Schematics are given as course material. They were not implemented as they are shown exactly. It depends on the elements used.
For example the op amp was a LM358, the Wheatstone bridge was made with restistors of 330Ω and a few other changes.

* robot_block_diagram : Instead of the proposed processor it was used the Arduino Leonardo
* robot_layout : Proposed layout of the circuits
* robot_schematic : Schematics of each of the necessary circuits
* code_flowchart : Final code flowchart to test the robot operation

## Notes

## Final product
