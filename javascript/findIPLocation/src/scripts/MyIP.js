const GetMyIp = () => {
    return fetch(`https://api.ipify.org?format=json`)
        .then((response) => {
            return response.json()
        }).then((res) => {
            document.querySelector('#my-ip').innerHTML = res.ip
        }).catch((err) => {
            alert("upps.. sepertinya ada yang salah")
            console.log(err)
        })
}

export default GetMyIp