from hashlib import md5, sha1, sha256, sha512

# Converts inputted text into various hash outputs
print('Welcome to the hashing function!')
unhashed_text = input('Enter text to be hashed: ')
encoded_text = unhashed_text.encode()
print('MD5:', md5(encoded_text).hexdigest())
print('Sha1:', sha1(encoded_text).hexdigest())
print('Sha256:', sha256(encoded_text).hexdigest())
print('Sha512:', sha512(encoded_text).hexdigest())
