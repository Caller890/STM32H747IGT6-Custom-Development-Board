# STM32H747IGT6 Custom Development Board

**STM32H747IGT6 Custom Development Board** built in **EasyEDA Pro** & **STM32CubeIDE**.

I created this board when I was in need of a dual-core project, however I could not find any custom boards online for the STM32H747 range, therefore I created this dev board and tested it.

This repository is intended for those seeking a custom design to integrate into their projects.  
⚠️ I would **not recommend using this design for actual operational hardware**.

For example, I use this dev board to test:
- Sensor acquisition  
- Communication  
- Build libraries  
...to integrate into my main projects.

---

## 📁 Project Overview

- Dual-core **STM32H747IGT6** (M7 – 480 MHz & M4 – 240 MHz)  
- **M7 & M4 System LEDs** (Controllable)  
- **16 x GPIO** (Input/Output)  
- **3 x Analog Inputs** (16-bit)  
- **3 x I²C Buses** (100 MHz)  
- **2 x SPI Interfaces**  
- **2 x 3.3 V Buses** (500 mA total)  
- **Communication via USB Bus**

---

## ⚙️ Project Structure

- Constructed in **STM32CubeIDE**  
- Programming `.elf` files through **STM32CubeProgrammer**  
- Future revision will allow **Arduino platform** (currently STM32CubeIDE only)  
- The board can be manufactured and pre-assembled by **JLCPCB**  
  - JLCPCB normally stocks all components  
  - A **stencil** is strongly recommended to prevent bridging on the MCU and regulator pins  

---

## 🧠 Instructions

Do **not** adjust source code outside the following files (unless you understand STM32 C architecture):

- `M7_Configuration.h / .c`  
- `M7_Sketch.h / .c`  
- `M7_Shared.h / .c`  
- `M4_Configuration.h / .c`  
- `M4_Sketch.h / .c`  
- `M4_Shared.h / .c`

### Notes:
- Any `#include` library files must be placed in **Configuration.h** for the required core.  
- `M7_Serial` allows `Serial.print()` style output (like Arduino).  
- `M7_Shared` & `M4_Shared` allow variable sharing between cores without cache clogging — both files **must match**.  
- `M7_CDC_User` ensures serial settings persist when the `.ioc` file is regenerated.  
- Upload code to **both M7 & M4 cores separately, first you need to generate .elf files by building code is CubeIDE.

  Hold **Boot** and **Reset** buttons simultaneously  
  Release **Reset** → enters boot mode  
  In **CubeProgrammer**, select USB → refresh COM ports → find dev board  
  Upload **M4 .elf** (do not reset)  
  Upload **M7 .elf**  
  Reset the board  

➡️ The **M7 core** always initiates the **M4 core** on boot-up.

---

## 🧩 Development Status

This dev board is in **early development**.  
As I use it more, I’ll continue updating the source code.  
I hope this helps others who struggled building STM32H747 projects.

💡 **Future update:** Full duplex communication between multiple dev boards via **SPI protocol**.
