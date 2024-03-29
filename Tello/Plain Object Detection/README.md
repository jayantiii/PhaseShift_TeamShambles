# IRIS Tello Demo

### Venv Installation

To download all the dependencies related to this project, begin by creating a Virtual Environment:

    python -m venv venv/

Activate the Venv by running:

    source venv/bin/activate

To deactivate, simply put:

    deactivate

Install all of the dependencies using:

    pip install -r requierments.txt
### How it Works

The Tello will carry out code running on a host computer connected to the broadcasting wifi signal coming from the drone itself. Through this network, the aircraft will execute receiving commands using UDP.

<img src="./IRIS%20Tello%20Demo%200c5e455c65a8456da11ddbd4c57b1610/diagram.png" alt="alt text" width="600"/>

source→[https://nanonets.com/blog/content/images/2018/11/thelist.png](https://nanonets.com/blog/content/images/2018/11/thelist.png)

Using the Tello SDK User Guide, as soon as the ML model detects a specified object in the input Tello video stream, it will send the Tello a command. The model uses the following classes:

background, aeroplane, bicycle, bird, boat, bottle, bus, car, cat, chair, cow,
diningtable, dog, horse, motorbike, person, pottedplant, sheep, sofa, train, tvmonitor

The bottle object is being used to carry out the demo. Once the object is detected, the *flip right* flip r, command is sent to the drone.

send('flip r')

<img src="./IRIS%20Tello%20Demo%200c5e455c65a8456da11ddbd4c57b1610/Draw-a-Water-Bottle-Step-11.jpg" alt="alt text" width="200"/>

<img src="./IRIS%20Tello%20Demo%200c5e455c65a8456da11ddbd4c57b1610/415yjHOgXVL.jpg" alt="alt text" width="285"/>


# Demo Obstacle Course

## Objective

The drone will begin detecting a bottle which will initiate the obstacle course, taking off the current position. Immediately after takeoff, the drone will rotate clockwise until a human is detected, which will then stop the rotating and land.

## Initiating Course

The drone will start the obstacle course by detecting a water bottle, and initiate the function:

send('takeoff')

### After takeoff, it will rotate until it detects a human

while(CLASSES[index] != 'person'){

send('cw 45')

}

<img src="https://thedatafrog.s3.amazonaws.com/media/images/Screen-Shot-2019-04-18-at-16.15.54.max-1000x500.png">

## Finalizing Course

After the while loop breaks, detecting the person, it will send the command:

send('land')