### Description
In this project, i made a simple program to detect the sum of coin available inside the frame. I used 3 type of coin, 1000, 500 and 100 IDR. This program used OpenCV 3.3 and Visual Studio Community as the editor.
This project needed constant environment to mantain the detection accuracy of the program i made. So, back then i made a box equipped with LED to make the light and distance from camera to the coin constant. The pictures regarding this project can be seen at the picture folder of this repository.

The following picture is a simple flowchart of the program 

[flowchart](https://github.com/falithurrahman/deteksi_koin/blob/master/Picture/Drawing1.jpg "Flowchart")

````C++
				if (luas > 14500 && luas <= 16000)
					koin = 500;
				else if (luas > 12500 && luas <= 14000)
					koin = 1000;
				else if (luas > 11000 && luas <= 12500)
					koin = 100;
````
Code from line 54 to 59 is used to determine which coin is detected based on the area of the circle. If the area is between 14500 to 16000 unit, it will be detected as 500. If the area is between 12500 to 14000 unit, it will be detected as 1000. If the area is between 11000 to 12500 unit, it will be detected as 100. These value will vary if the distance between camera and the object is changed. When i did this project, i mantained the distance between camera and object about 20cm. **If the distance change, the area of coin detected will also change.**