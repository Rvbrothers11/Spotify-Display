# Spotify-Display
A 3D printed touchscreen spotify display!


**What inspired me to make it:**
I am a really lazy individual who has recently started listening to alot of songs. However, sometimes, the songs that play are a little boring so I want to switch to the next song, or really good such that I want to listen to the song again, or just keep track of the song length and time passed. Instead of switching on my phone or switching tabs on my laptop I wanted a faster and easier way to do this. ENTER: Spotify Display!!!!!!

**What is it:**
This project is literally as the name suggests, a spotify displayyy! The aim of this is to allow users to be able keep track of their songs, easily switch between songs and change songs, without actually turning their laptop or phone on. It uses a touchscreen display with buttons and a song bar to address these issues. 


Final Model Image:

<img width="1032" height="733" alt="image" src="https://github.com/user-attachments/assets/ec498aa7-0e9f-4604-8a37-42c4c3f3f0a4" />



How to build and use?
Start by 3D printing these 3 pieces found in the CAD folder:

Main Case:

<img width="1189" height="795" alt="image" src="https://github.com/user-attachments/assets/0b6cf0e9-c522-4047-beb3-f2090453162b" />


Top Cover:

<img width="1017" height="607" alt="image" src="https://github.com/user-attachments/assets/c379bc45-0990-455c-b88c-54c370d116f4" />


Back Cover:

<img width="831" height="893" alt="image" src="https://github.com/user-attachments/assets/5fd45095-6180-4e49-b0ea-3bc24876d57c" />


Add the heat inserts into their respective holes:

<img width="1147" height="1105" alt="image" src="https://github.com/user-attachments/assets/ae9df76c-0ba4-4ad8-8219-fa82c21b9555" />


Add the TFT display and the C3 mini microcontroller:

<img width="1153" height="845" alt="image" src="https://github.com/user-attachments/assets/83d91212-df8d-4bed-99fc-794958c89d2a" />


Connect as per the wiring diagram given below using jumper wires and close the model using the covers using M2x6mm screws:

<img width="1157" height="866" alt="image" src="https://github.com/user-attachments/assets/d56060d9-90b4-4f8b-9f5b-34bfef90a590" />


Connect the C3 to your laptop using a C-type wire or whatever is required. Upload the code given in the Code folder, run the code and when prompted add your wifi ssid, spotify api key. 

Voila! Your own Spotify Display!!!

Wiring Diagram:

<img width="1066" height="1013" alt="image" src="https://github.com/user-attachments/assets/afae244a-ab2d-49dd-a007-2387f5ca26a3" />


Bill of Materials:
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
<div class="container">
    <h1>Bill of Materials</h1>
    <table>
        <thead>
            <tr>
                <th>Product</th>
                <th>Description</th>
                <th style="text-align: center;">Qty</th>
                <th class="price-col">Unit Price ($)</th>
                <th class="price-col">Total Price ($)</th>
                <th>Link</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>2.4 inch Touch Screen TFT Display Module</td>
                <td>2.4-inch SPI Interface 240x320 Touch Screen TFT Colour Display Module</td>
                <td style="text-align: center;">1</td>
                <td class="price-col">$6.170</td>
                <td class="price-col">$6.170</td>
                <td><a href="https://robu.in/product/2-4-inch-spi-interface-240x320-touch-screen-tft-colour-display-module/" target="_blank">View Link</a></td>
            </tr>
            <tr>
                <td>ESP32-C3 Mini Development Board</td>
                <td>ESP32-C3 Mini Development Board (Unsoldered)</td>
                <td style="text-align: center;">1</td>
                <td class="price-col">$2.820</td>
                <td class="price-col">$2.820</td>
                <td><a href="https://robocraze.com/products/esp32-c3-mini-development-board-unsoldered" target="_blank">View Link</a></td>
            </tr>
            <tr>
                <td>3D Print</td>
                <td>Custom 3D printed components</td>
                <td style="text-align: center;">1</td>
                <td class="price-col">$5.000</td>
                <td class="price-col">$5.000</td>
                <td>N/A</td>
            </tr>
            <tr>
                <td>F2F Jumper Wires</td>
                <td>F2F Jumper Wires 20cm 20pcs</td>
                <td style="text-align: center;">1</td>
                <td class="price-col">$0.340</td>
                <td class="price-col">$0.340</td>
                <td><a href="https://robocraze.com/products/f2f-jumper-wires-20cm-20pcs" target="_blank">View Link</a></td>
            </tr>
            <tr>
                <td>M2 x 4mm Brass Threaded Inserts</td>
                <td>M2 x 4mm Brass Threaded Inserts</td>
                <td style="text-align: center;">6</td>
                <td class="price-col">$0.021</td>
                <td class="price-col">$0.126</td>
                <td><a href="https://onlyscrews.in/products/m2-x-4mm-brass-threaded-inserts" target="_blank">View Link</a></td>
            </tr>
            <tr>
                <td>M2 x 6mm Phillips CSK SS 304 Screw</td>
                <td>M2 x 6mm Phillips CSK SS 304 Screw (Dia 2mm, Length 6mm)</td>
                <td style="text-align: center;">6</td>
                <td class="price-col">$0.013</td>
                <td class="price-col">$0.078</td>
                <td><a href="https://onlyscrews.in/products/m2-x-6mm-phillips-csk-ss-304-screw" target="_blank">View Link</a></td>
            </tr>
            <tr class="grand-total">
                <td colspan="4" style="text-align: right;">GRAND TOTAL</td>
                <td class="price-col">$14.534</td>
                <td></td>
            </tr>
        </tbody>
    </table>
</div>

</body>
</html>

Zine Image:

<img width="786" height="1212" alt="image" src="https://github.com/user-attachments/assets/970af3e8-9bc3-4f15-aa98-694c0a314517" />


