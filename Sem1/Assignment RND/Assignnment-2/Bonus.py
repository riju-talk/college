import requests
def is_real(x):
    exists=requests.get(f"https://api.dictionaryapi.dev/api/v2/entries/en/{x}").json()
    n_exists=requests.get(f"https://api.dictionaryapi.dev/api/v2/entries/en/{x}").json()
    try:
        m=exists[0]["word"]
    except KeyError:
        m=n_exists["title"]  
    if(m==x):
        return True
    else:
        return False
print(is_real("plp"))