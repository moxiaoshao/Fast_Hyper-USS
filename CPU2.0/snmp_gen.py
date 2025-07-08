import csv

input_csv_file = './SNMPDataset_SNMP_03110_OR_03111.csv'
output_txt_file = './CPU2.0/snmp_2.txt'

column_indices = [12, 14] # , 11, 1, 5, 13, 9, 8, 10, 21, 15]

try:
    with open(input_csv_file, 'r', newline='') as infile, open(output_txt_file, 'w') as outfile:
        reader = csv.reader(infile)

        for row in reader:
            try:
                extracted_data = [row[i] for i in column_indices]
                
                output_line_data = ["1"] + extracted_data
                
                outfile.write(" ".join(output_line_data) + "\n")
            except IndexError:
                print(f"Warning: Skipping malformed row: {row}")

    print(f"Data has been successfully processed and saved to: {output_txt_file}")

except FileNotFoundError:
    print(f"File not found: {input_csv_file}")
except Exception as e:
    print(f"Error occurred during processing: {e}")