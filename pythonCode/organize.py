#!/usr/bin/env python3

"""
A command-line utility to organize files in a target directory
by their file extension.

This script iterates through files in a specified directory,
categorizes them based on their extension, and moves them into
new sub-directories (e.g., 'PDFs', 'Images', 'Videos').

Features:
- Categorizes files using a predefined mapping.
- Creates destination folders if they don't exist.
- Handles file name collisions by appending a number.
- Includes a --dry-run option to simulate without moving files.
- Logs all actions for review.
"""

import argparse
import logging
import shutil
from pathlib import Path
from typing import Dict, List

# --- Configuration ---

# 1. Define category mappings for file extensions.
#    You can easily add or change categories here.
FILE_CATEGORIES: Dict[str, List[str]] = {
    "Images": [".jpg", ".jpeg", ".png", ".gif", ".bmp", ".svg", ".webp"],
    "Videos": [".mp4", ".mkv", ".mov", ".avi", ".wmv", ".flv"],
    "Audio": [".mp3", ".wav", ".aac", ".flac", ".ogg"],
    "Documents": [".pdf", ".doc", ".docx", ".xls", ".xlsx", ".ppt", ".pptx", ".txt", ".rtf"],
    "Archives": [".zip", ".rar", ".7z", ".tar", ".gz"],
    "Code": [".py", ".js", ".ts", ".html", ".css", ".scss", ".java", ".c", ".cpp", ".go", ".rs"],
    "Executables": [".exe", ".msi", ".dmg", ".app", ".bat", ".sh"],
    "Fonts": [".ttf", ".otf", ".woff", ".woff2"],
}

# 2. Name for the folder to hold uncategorized files
OTHER_FOLDER = "Other"

# 3. Set up logging
logging.basicConfig(
    level=logging.INFO,
    format="[%(levelname)s] %(message)s",
    handlers=[logging.StreamHandler()]
)

# --- Helper Functions ---

def get_category_name(extension: str) -> str:
    """Finds the category name for a given file extension."""
    for category, extensions in FILE_CATEGORIES.items():
        if extension in extensions:
            return category
    return OTHER_FOLDER

def get_unique_path(destination_path: Path) -> Path:
    """
    Checks if a file path exists. If it does, appends a number
    to the filename until a unique path is found.
    e.g., 'image.png' -> 'image_1.png' -> 'image_2.png'
    """
    if not destination_path.exists():
        return destination_path

    original_stem = destination_path.stem
    original_suffix = destination_path.suffix
    counter = 1

    while True:
        new_filename = f"{original_stem}_{counter}{original_suffix}"
        new_path = destination_path.with_name(new_filename)
        if not new_path.exists():
            return new_path
        counter += 1

# --- Core Logic ---

def organize_directory(target_dir: Path, is_dry_run: bool = False):
    """
    Organizes all files in the target directory.
    """
    if not target_dir.is_dir():
        logging.error(f"Error: Path '{target_dir}' is not a valid directory.")
        return

    logging.info(f"Scanning directory: {target_dir}")
    if is_dry_run:
        logging.info("--- DRY RUN ENABLED: No files will be moved. ---")

    file_count = 0
    moved_count = 0

    # Iterate over all items in the target directory
    for item in target_dir.iterdir():
        # Skip directories and hidden files
        if item.is_dir() or item.name.startswith('.'):
            continue
        
        # This is a file we can process
        if item.is_file():
            file_count += 1
            file_ext = item.suffix.lower()

            # 1. Determine the destination folder
            if not file_ext:
                category = OTHER_FOLDER
            else:
                category = get_category_name(file_ext)
            
            dest_folder = target_dir / category

            # 2. Create the destination folder if it doesn't exist
            if not dest_folder.exists() and not is_dry_run:
                try:
                    dest_folder.mkdir()
                    logging.info(f"Created new folder: {dest_folder}")
                except OSError as e:
                    logging.error(f"Error creating folder {dest_folder}: {e}")
                    continue
            
            # 3. Handle potential file name collisions
            final_dest_path = get_unique_path(dest_folder / item.name)

            # 4. Move the file
            if is_dry_run:
                logging.info(f"DRY RUN: Would move '{item.name}' -> '{final_dest_path.relative_to(target_dir)}'")
            else:
                try:
                    shutil.move(str(item), str(final_dest_path))
                    logging.info(f"Moved '{item.name}' -> '{final_dest_path.relative_to(target_dir)}'")
                    moved_count += 1
                except Exception as e:
                    logging.error(f"Error moving file '{item.name}': {e}")

    # --- Summary ---
    logging.info("\n--- Organization Summary ---")
    if is_dry_run:
        logging.info(f"DRY RUN: Found {file_count} files that would be moved.")
    else:
        logging.info(f"Scan complete. Found {file_count} files.")
        logging.info(f"Successfully moved {moved_count} files.")
    logging.info("----------------------------\n")

# --- Entry Point ---

def main():
    """
    Parses command-line arguments and starts the organization.
    """
    parser = argparse.ArgumentParser(
        description="Organize files in a directory by extension.",
        epilog="Example: python organize.py /path/to/your/downloads --dry-run"
    )

    parser.add_argument(
        "target_dir",
        type=str,
        help="The target directory to organize."
    )

    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Simulate the organization without moving any files."
    )

    args = parser.parse_args()
    
    # Convert the string path to a Path object
    target_directory = Path(args.target_dir)

    organize_directory(target_directory, args.dry_run)

if __name__ == "__main__":
    main()