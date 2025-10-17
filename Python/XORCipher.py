def encrypt_xor(plaintext, key):
    encrypted_text = "".join(chr(ord(char) ^ key) for char in plaintext)
    return encrypted_text

# Example usage
plaintext = "Hello World"
key = 5  # XOR key (can be any integer value)
encrypted = encrypt_xor(plaintext, key)
print(f"Encrypted Text (XOR Cipher): {encrypted}")

# Decrypting is done by applying the same XOR operation
decrypted = encrypt_xor(encrypted, key)
print(f"Decrypted Text (XOR Cipher): {decrypted}")
