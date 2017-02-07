# EE183DA Lab 2
#The Glass Xylophone (On a Budget)
## Introduction
This is the README for Lab 2 of EE183DA, Winter 2017. Given a wifi-capable microcontroller (ESP12e), a standard servo, and a continuous-rotation servo, we were tasked to construct an electromechanical device with both autonomous and human-controlled functions, commanded via an internet-based web interface.

## Design Description
With the provided materials (microcontroller and two servos), I decided that two feasible methods for creating sound were either some guitar-like or drum-like mechanism. After testing some crude designs involving rubber bands as strings, I quickly discovered that the servos did not generate enough torque to adequately pluck a rubber band held at sufficient tension to generate a decent pitch, so I moved on to searching for a feasible drum-like design. 

As I had two servos, it made the most sense to use one to rotate in the x-y plane and the other to rotate perpendicularly to the x-y plane so that I could have a range of areas to hit (thereby increasing the variety of generatable pitches) arranged in a semi-circle. Since my roommate, being premed, had recently consumed a large quantity of Starbucks coffee in glass containers, I decided to repurpose them for my project, adding water to control the pitch of each can. I found I could get approximately 5-6 decent pitches out of the set before the lowest pitch can overflowed and the highest pitch can was completely empty, which was sufficient for this project. I used a coffee stirrer as the arm as it was light and therefore not too much of a strain on the servo, and duct tape to hold everything in place. The paperclip/rubber band combo as the stand was something of an experiment and it seemed to work as I did not have stability issues with the bottom servo falling over or moving again after I implemented it. 

I soon realized I needed some metallic object at the tip of my coffee stirrer arm as the wood wasn't generating enough sound, so I found some spare change and figured that the dime being the smallest would also be the lightest and most suitable for the servo arm. I also found that I would need to use a couple more dimes as counterweights to prevent the top servo from agitating too much and falling off. Even so, it was necessary for me to hold it steady as I had decided not to secure the connection between the servo axle and mount via a screw for ease of assembly/disassembly. All the materials apart from the core microcontroller and servos were all more or less household items that are readily available.

![alt text][logo_1]
[logo_1]: https://github.com/Angraecinae/EE183DA_Lab_2/blob/master/16427307_1231730040251240_893262621608351921_n.jpg "Figure 1"
Figure 1: 
![alt text][logo_2]
[logo_2]: https://github.com/Angraecinae/EE183DA_Lab_2/blob/master/16427464_1231730046917906_7447679213757880000_n.jpg "Figure 2"
Figure 2:
![alt_text][logo_3]
[logo_3]: https://github.com/Angraecinae/EE183DA_Lab_2/blob/master/16427631_1231730043584573_1406056857316235496_n.jpg "Figure 3"
Figure 3:
![alt_text][logo_4]
[logo_4]: https://github.com/Angraecinae/EE183DA_Lab_2/blob/master/16473467_1231730050251239_1158671850709158401_n.jpg "Figure 4"
Figure 4:
## Bill of Materials
- ESP12e Microcontroller (1x | $5.95)
- ESP8266 Shield (1x | $14.95)
- Standard Servo (1x | $3.95)
- Continuous-Rotation Servo (1x | $5.95)
- Duct Tape (1x | $2.99)
- Coffee Stirrers (5x | Free if you go to the right places)
- Dime (3x | $0.30)
- Paper Clip Large (1x | $0.10)
- Rubber Bands (4x | $0.40)
- Starbucks Coffee Cold (6-8x | $$$, but I got them used so...)

## Operation Manual
The image below features the main webpage, which contains all the button functions. The notes 'G' through 'E' represent the six manual note options the user can click to play that particular note. The 'Calibrate' function simply runs the device in an ascending then descending scale to allow the user to move the glasses into place to ensure best contact between the striker and glasses. The 'Track 1' option under 'Play Songs' allows the user to play a preset musical track (I only had time to program one tune in, but it's not that difficult to add more).
![alt_text][logo_5]
[logo_5]: https://github.com/Angraecinae/EE183DA_Lab_2/blob/master/Capture.PNG "Figure 5"
Figure 5: Screenshot of main webpage.

## Demonstration
The below video demonstrates the glass xylophone in its auto mode, in which it plays Track 1, the melody of Ode to Joy from Beethoven's 9th. 

## Future Improvement(s)
Obviously, the use of duct tape, coffee stirrers, paper clip(s), and rubber bands were intended as low-cost materials with high ease-of-access for the purpose of prototyping and proof-of-concept. A more concrete version should make use of 3-D printing to make more secure mounts and joint connections for the two servos. Ideally, two standard servos should be used as the continuous-rotation servo is not precise enough without the use of guides to serve as a precision striker. The dimes were an easy metallic contact with clearer resonance as a striking element, and were also decent counterweights, but could be replaced by more formal materials. The coffee glasses could be replaced by larger and more resonant (and probably expensive) wine glasses with a broader range, to also allow for more notes to be played (currently limited to 5-6). Additionally, an expansion of its software capabilities, such as the ability to record and save tracks, would greatly increase its playability.   
