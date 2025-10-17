import MyIP from './MyIP.js'

const API_KEY = 'at_KjaWnt18FmscPPsWiuqlO4oAx7cSg'

const main = () => {

    MyIP()

    const InputElement = document.querySelector('input-component')
    const ResultElement = document.querySelector('result-component')


    const GetResult = () => {
        return fetch(`https://geo.ipify.org/api/v1?apiKey=${API_KEY}&ipAddress=${InputElement.value}`)
            .then((response) => {
                return response.json()
            }).then((res) => {
                ResultElement.dataResult = res
            }).catch((err) => {
                alert("upps.. sepertinya ada yang salah")
                console.log(err)
            })
    }

    InputElement.onClickEvent = GetResult
}

export default main