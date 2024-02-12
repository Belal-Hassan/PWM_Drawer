<a name="readme-top"></a>
<hr>
<br />
<div align="center">
  <a href="https://github.com/Belal-Hassan/PWM_Drawer">
  </a>
<h3 align="center">PWM Drawer</h3>
  <p align="center">
    <br />
    <a href="https://github.com/Belal-Hassan/PWM_Drawer"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Belal-Hassan/PWM_Drawer">View Demo</a>
    ·
    <a href="https://github.com/Belal-Hassan/PWM_Drawer/issues">Report Bug</a>
    ·
    <a href="https://github.com/Belal-Hassan/PWM_Drawer/issues">Request Feature</a>
  </p>
</div>
<hr>


<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#About-The-Project">About The Project</a>
      <ul>
        <li><a href="#Built-With">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#Technical-Specifications">Technical Specifications</a>
      <ul>
        <li><a href="#Working-Principle">Working Principle</a></li>
      </ul>
      <ul>
        <li><a href="#Flowchart">Flowchart</a></li>
      </ul>
      <ul>
        <li><a href="#Schematic-Diagram">Schematic Diagram</a></li>
      </ul>
    </li>
    <li><a href="#Contact">Contact</a></li>
  </ol>
</details>

## About The Project

The ATtiny84 PWM Wave Drawing Project utilizes the capabilities of the ATtiny84 microcontroller to visualize Pulse Width Modulation (PWM) waves generated by an external signal generator 
on an LCD display. This innovative project offers an exploration of microcontroller interfacing and signal processing using Timer 1 of the microcontroller. The ATtiny84, a compact yet powerful 
microcontroller, interprets the incoming PWM signals and displays their Frequencies and Duty cycles, then translates the input wave into a visual representation. With this compact device, users 
can observe and analyze the waveform characteristics. 

Note: A proteus simulation project is included in the project files.

### Built With
<img src="https://www.nicepng.com/png/detail/877-8775163_microchip-technology-logo.png" height = "40" width = "150" >

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Technical Specifications

The project has the following unique specifications and charactristics:

1. It can measure _from 501Hz to 100kHz_.
2. _99% accuracy_ was achieved in the 100kHz range.
3. The project can display up to _4 significant figures_ for frequency measurement.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Working Principle

The main principle of operation is using the input capture unit (ICU) of ATtiny84’s Timer 1 to measure the frequency and duty cycle using the following steps:

1. The ICU captures the time between 3 consecutive edges of the input PWM wave (2 rising, 1 falling).
2. The frequency is calculated getting the reciprocal of the time difference between the 1st and 3rd captures (Period).
3. The duty cycle is calculated by dividing the time difference between 1st and 2nd captures by the Period. 

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Flowchart

![Blank diagram](https://github.com/Belal-Hassan/PWM_Drawer/assets/141426674/26e98036-5744-434f-81c7-63017fbb7876)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Schematic Diagram

![Graduation_Project_Schematic](https://github.com/Belal-Hassan/PWM_Drawer/assets/141426674/9bb0ab7c-1e25-49e2-814c-6e0174301c61)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

Belal - belal.34327@gmail.com, bilal.1021023@stemegypt.edu.eg

Project Link: [https://github.com/Belal-Hassan/PWM_Drawer](https://github.com/Belal-Hassan/PWM_Drawer.git)
<p align="right">(<a href="#readme-top">back to top</a>)</p>
