# STM32H747IGT6 Custom Development Board

# 

# STM32H747IGT6 Custom Development Board Built in EasyEDA Pro \& STM32CubeIDE.



# I created this board when I was in need of dual core project , however I could not find any custom boards online for the STM32H747 range, therefore I created this dev board and tested.



# This Repository is intended for those seeking custom design to integrate into their projects, I would not recommend using this design for actual operational hardware. 



# For example I use this dev board to test Sensors Acquisition, Communication, Build Libraries, etc to integrate into my main projects!  



# 

# ---

# 

# 📁 Project Overview

# \- Dual-core STM32H747IGT6(M7-480Mhz \& M4-240Mhz)

# \- M7 \& M4 System LED (Controllable)

# \- 16 x GPIO (Input/Output)

# \- 3 x Analog (16bit)

# \- 3 x I2C Bus (100Mhz) 

# \- 2 x SPI

# \- 2 x 3V3 Bus (500mA Total)

# \- Communication via USB Bus

# 

# ---

# 

# ⚙️ Project Structure



# \- Constructed in STM32 CubeIDE.

# \- Programming .elf files through STM32 Cube Programmer. 

# \- Future revision will allow Arduino platform, however currently can only be coded in CubeIDE.

# \- The board can be manufactured and pre-assembled by JLCPCB, they normally have all components in stock or the board can be self-assembled. I strongly recommend using a stencil to prevent bridging on the MCU \& regulator pins.

# 

# ---



# 🧠 Instructions 

# \- I do not recommend adjusting any of the source code outside of following files 

* # M7 Configuration.h
* # M7 Configuration.c
* # M7 Sketch.h
* # M7 Sketch.c 
* # M7 Shared.h
* # M7 Shared.c
* # M4 Configuration.h
* # M7 Configuration.c
* # M4 Sketch.h
* # M4 Sketch.c
* # M4 Shared.h
* # M4 Shared.c



# Unless you have a good understanding of STM32 \*C\* Architecture.

# \- Any #include library files must be placed in configuration.h on the required core.

# \- M7\_Serial allow you to serial print as you would in Arduino environment, this is the same for entering charters into serial monitor to control a switch , etc.

# \- M7\_Shared \& M4\_Shared allow you to share variables between each core without clogging cache, both M7 \& M4 Shared.h and Shared.c must always be the same. Refer to example in source code.

# \- Uploading code must be done to both M7 \& M4 cores separately. Hold both Boot \& Reset button at the same time then release Reset, this will enter boot mode.

# 

# In Cube Programmer select USB and refresh COM ports, find the COM port related to dev board. Start by uploading the M4 .elf file (Do not reset) followed by the M7 .elf file. Then reset



# The M7 core will always initiate the M4 core on boot up.



# ---



# This dev board is in early development, as I use it more I will update source code as I go, I hope this helps others with the struggles I had trying to build a project using STM32H747 range.



# Soon this dev board will be capable of full duplex communication between multiple dev boards via SPI Protocol!  











