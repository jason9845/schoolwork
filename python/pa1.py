# Tushar Jain 20142361 tjain@connect.ust.hk

# COMP1021 Lab 3 Music Player

import pygame.midi  # Import the midi module for playing music
import time         # Import the time module for the time.sleep function
import turtle
##### Initialize the modules

# Initialize the MIDI (playing music) module
pygame.midi.init()

# Create an output to play music
output = pygame.midi.Output(pygame.midi.get_default_output_id())

def displaymusic():
    turtle.reset()  
    duration = music[-1][0] 
    turtle.mode('world') 
    turtle.setworldcoordinates(0, 0, duration, 127) 
    turtle.hideturtle() 
    turtle.tracer(False)
    turtle.up()
    for event in music:
        if event[2] == 'On':
            turtle.goto(event[0], event[1])
            turtle.dot(5)
    turtle.update()
    turtle.done()

# Initialize the music list
music = []
# Initialize the instrument list
instruments = [
    'Acoustic Grand Piano', 'Bright Acoustic Piano', 'Electric Grand Piano',
    'Honky-tonk Piano', 'Electric Piano 1', 'Electric Piano 2', 'Harpsichord',
    'Clavinet', 'Celesta', 'Glockenspiel', 'Music Box', 'Vibraphone',
    'Marimba', 'Xylophone', 'Tubular Bells', 'Dulcimer', 'Drawbar Organ',
    'Percussive Organ', 'Rock Organ', 'Church Organ', 'Reed Organ',
    'Accordion', 'Harmonica', 'Tango Accordion', 'Acoustic Guitar (nylon)',
    'Acoustic Guitar (steel)', 'Electric Guitar (jazz)',
    'Electric Guitar (clean)', 'Electric Guitar (muted)', 'Overdriven Guitar',
    'Distortion Guitar', 'Guitar Harmonics', 'Acoustic Bass',
    'Electric Bass (finger)', 'Electric Bass (pick)', 'Fretless Bass',
    'Slap Bass 1', 'Slap Bass 2', 'Synth Bass 1', 'Synth Bass 2', 'Violin',
    'Viola', 'Cello', 'Contrabass', 'Tremolo Strings', 'Pizzicato Strings',
    'Orchestral Harp', 'Timpani', 'String Ensemble 1', 'String Ensemble 2',
    'Synth Strings 1', 'Synth Strings 2', 'Choir Aahs', 'Voice Oohs',
    'Synth Choir', 'Orchestra Hit', 'Trumpet', 'Trombone', 'Tuba',
    'Muted Trumpet', 'French Horn', 'Brass Section', 'Synth Brass 1',
    'Synth Brass 2', 'Soprano Sax', 'Alto Sax', 'Tenor Sax', 'Baritone Sax',
    'Oboe', 'English Horn', 'Bassoon', 'Clarinet', 'Piccolo', 'Flute',
    'Recorder', 'Pan Flute', 'Blown Bottle', 'Shakuhachi', 'Whistle',
    'Ocarina', 'Lead 1 (square)', 'Lead 2 (sawtooth)', 'Lead 3 (calliope)',
    'Lead 4 (chiff)', 'Lead 5 (charang)', 'Lead 6 (voice)', 'Lead 7 (fifths)',
    'Lead 8 (bass + lead)', 'Pad 1 (new age)', 'Pad 2 (warm)',
    'Pad 3 (polysynth)', 'Pad 4 (choir)', 'Pad 5 (bowed)', 'Pad 6 (metallic)',
    'Pad 7 (halo)', 'Pad 8 (sweep)', 'FX 1 (rain)', 'FX 2 (soundtrack)',
    'FX 3 (crystal)', 'FX 4 (atmosphere)', 'FX 5 (brightness)',
    'FX 6 (goblins)', 'FX 7 (echoes)', 'FX 8 (sci-fi)', 'Sitar', 'Banjo',
    'Shamisen', 'Koto', 'Kalimba', 'Bagpipe', 'Fiddle', 'Shanai',
    'Tinkle Bell', 'Agogo', 'Steel Drums', 'Woodblock', 'Taiko Drum',
    'Melodic Tom', 'Synth Drum', 'Reverse Cymbal', 'Guitar Fret Noise',
    'Breath Noise', 'Seashore', 'Bird Tweet', 'Telephone Ring', 'Helicopter',
    'Applause', 'Gunshot']

print('Welcome to the Python music player!')

# The following while loop shows the menu options
# to the user, gets the response from the user,
# and does the appropriate action

# Initialize the option to empty so we can
# do the while loop the first time
option = ''

while option != 'q': # While the option is not 'q'
    print()
    print('Please choose one of the following options:')
    print()
    print('l - Load a music file')
    print('p - Play the music')
    print('i - Change the musical instrument')
    print('t - Transpose the music')
    print('s - Adjust the speed of the music')
    print('d - Display the music')
    print('a - Add a delay & note to the end')
    print("k - 'Kill' the music by removing all music data")
    print('m - Play the music as drums n times')
    print('r - Reverse the music')
    print('q - Quit the program')
    print()

    option = input('Please input your option: ')

    '''
    The following code loads the music information
    into the event data structure.
    You aren't expected to understand exactly how it
    works, so don't worry about it!
    '''
    ##### Handle the load option
    if option == 'l':
        print()

        # Ask the user for the music file
        musicfile = input('Please give me a music file: ')

        # Open the file for reading
        f = open(musicfile, 'r')

        # Read the data into the music list
        music = []
        for line in f:
            # Read each line as a music event
            event = line.rstrip().split("\t")

            # Convert the data to the right data type
            event[0] = float(event[0])  # Time
            event[1] = int(event[1])    # Pitch

            # Add the event at the end of the music
            music.append(event)

        # Close the file
        f.close()
    '''
    End of the scary code
    '''

    ##### Handle the play option
    if option == 'p':
        print()

        for i in range(len(music)):
            event = music[i]
            if event[2] == "On":
                output.note_on(event[1], 127) ### event [1] stores the pitch
            else:
                output.note_off(event[1], 127)
            # Maintain the correct timing
            if i+1 < len(music):
                next_event = music[i+1]
                time.sleep(next_event[0] - event[0])
                               
    ##### Handle the instrument option

    if option == 'i':
        print()    
        instrument = input("Please enter the instrument number: ")
        output.set_instrument(int(instrument))
        
    if option == 't':
        print()
        transpose_value = input("Please enter the amount of transposition: ")
        for event in music:           
            event[1] = event[1] + int(transpose_value)
            if event[1] > 127:
                event[1] = 127
            elif event[1] < 0:
                event[1] = 0

    if option == 's':
        print()
        music_speed = input('Please enter the desired speed in terms of percentage: ')
        speed_number = int(music_speed)/100
        for event in music:
            event[0] = event[0]/speed_number # Change the time value
        
    if option == 'd':
        print()
        print('Please switch to the turtle window to see the music display.')
        displaymusic()

    if option == 'a':
        print()
        delay = input('Please enter the delay (in seconds): ')
        pitch = input('Please enter the pitch of the note: ')
        duration = input('Please enter how long the note lasts (in seconds): ') 
        music.append([float(delay) + float(music[-1][0]), int(pitch), 'On'])
        music.append([float(duration) + float(music[-1][0]), int(pitch), 'Off'])

    if option == 'k':
        print()
        music = []    

    if option == 'm':
        print()
        repeat = input('Please enter the number of times you want to repeat: ')
        for i in range(int(repeat)):
            for i in range(len(music)):
                event = music[i]
                if event[2] == "On":
                    output.note_on(event[1], 127, 9)
                else:
                    output.note_off(event[1], 127, 9)
                # Maintain the correct timing
                if i+1 < len(music):
                    next_event = music[i+1]
                    time.sleep(next_event[0] - event[0])

    if option == 'r':
        print()
        music = music[::-1]
        for i in range(1, len(music)+1):
            music[-i][0] = float(music[0][0]) - float(music[-i][0])
        for event in music:
            if event[2] == "On":
                event[2] = "Off"
            elif event[2] == "Off":
                event[2] = "On"
        
# Close the music output
output.close()

# Close the MIDI module
pygame.midi.quit()
