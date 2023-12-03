#!/bin/bash

# Define the data file
data_file="student_records.txt"
data_temp="temp_records.txt"
# Function to display the menu
display_menu() {
    echo "Menu:"
    echo "1) Display all records"
    echo "2) Insert new record"
    echo "3) Delete particular record"
    echo "4) Update student information"
    echo "5) Exit"
}

# Function to display all records
display_records() {
    echo "Student Records:"
    column -t -s "|" "$data_file"
}

# Function to check if a roll exists in the data file
roll_exists() {
    local roll_to_check="$1"
    if grep -q "^$roll_to_check" "$data_file"; then
        return 0  # Roll exists
    else
        return 1  # Roll does not exist
    fi
}

# Function to insert a new record
insert_record() {
    echo "Enter roll:"
    read roll
    if roll_exists "$roll"; then
        echo "Record with roll $roll already exists."
    else
        echo "Enter name:"
        read name
        echo "Enter department:"
        read department
        echo "Enter SGPA:"
        read sgpa
        echo "$roll | $name | $department | $sgpa" >> "$data_file"
        echo "Record inserted successfully."
    fi
}

# Function to delete a particular record
delete_record() {
    echo "Enter roll to delete:"
    read roll
    if roll_exists "$roll"; then
        grep -v "^$roll" "$data_file" > "$data_file.tmp"
        mv "$data_file.tmp" "$data_file"
        echo "Record deleted successfully."
    else
        echo "Record with roll $roll not found."
    fi
}

# Function to update student information
update_record() {
    echo "Enter roll to update:"
    read roll
    if roll_exists "$roll"; then
        echo "Choose the field to update:"
        echo "1) Name"
        echo "2) Department"
        echo "3) SGPA"
        read update_choice

        case $update_choice in
            1)
                echo "Enter new name:"
                read new_name
                updated_record=$(grep "^$roll" "$data_file" | cut -d "|" -f 1)" | $new_name |"$(grep "^$roll" "$data_file" | cut -d "|" -f 3-4)
                ;;
            2)
                echo "Enter new department:"
                read new_department
                updated_record=$(grep "^$roll" "$data_file" | cut -d "|" -f 1-2)" | $new_department |"$(grep "^$roll" "$data_file" | cut -d "|" -f 4)
                ;;
            3)
                echo "Enter new SGPA:"
                read new_sgpa
                updated_record=$(grep "^$roll" "$data_file" | cut -d "|" -f 1-3)" | SGPA $new_sgpa"
                ;;
            *)
                echo "Invalid choice."
                return
                ;;
        esac

        grep -v "^$roll" "$data_file" > "$data_file.tmp"
        echo "$updated_record" >> "$data_file.tmp"
        mv "$data_file.tmp" "$data_file"
        echo "Record updated successfully."
    else
        echo "Record with roll $roll not found."
    fi
}

# Main loop
while true; do
    display_menu
    read choice

    case $choice in
        1)
            display_records
            ;;
        2)
            insert_record
            ;;
        3)
            delete_record
            ;;
        4)
            update_record
            ;;
        5)
            echo "Exiting."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please choose again."
            ;;
    esac
done

