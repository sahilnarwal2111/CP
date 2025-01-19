# File names
file1 = 'txt1.txt'
file2 = 'txt2.txt'

# Read files
with open(file1, 'r') as f1, open(file2, 'r') as f2:
    lines1 = f1.readlines()
    lines2 = f2.readlines()

# Ensure both files have the same number of lines
if len(lines1) != len(lines2):
    print("Files have different numbers of lines.")
else:
    print("Lines with different values:")
    # Compare line by line
    for i, (line1, line2) in enumerate(zip(lines1, lines2), start=1):
        if line1.strip() != line2.strip():
            print(f"Line {i}: {line1.strip()} != {line2.strip()}")
