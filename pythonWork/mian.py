import os
import cv2
import pytesseract
import pandas as pd
from PIL import Image

# Path to your image
image_path = "/Users/sahilnarwal/Desktop/screenShot/Screenshot 2024-10-27 at 8.27.14 AM.png"
output_csv = "/Users/sahilnarwal/Desktop/screenShot/output.csv"

# Load the image and convert it to grayscale
img = cv2.imread(image_path)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


# Use thresholding to improve OCR accuracy for table data
_, thresh = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY_INV)

# Use pytesseract to extract table-like text from the image
custom_config = r'--oem 3 --psm 6'
text = pytesseract.image_to_string(thresh, config=custom_config)

# Split the extracted text into rows based on newlines
rows = [line for line in text.split('\n') if line.strip()]

# Parse the rows into structured columns
data = []
for row in rows:
    # Split each row based on whitespace or multiple spaces
    columns = row.split()
    if len(columns) >= 4:
        # Append data for each row
        data.append(columns)

# Convert the extracted data into a DataFrame
df = pd.DataFrame(data, columns=["Date-Time", "Number", "Duration", "Charges"])

# Save the DataFrame to CSV
df.to_csv(output_csv, index=False)
print(f"Data saved to {output_csv}")
