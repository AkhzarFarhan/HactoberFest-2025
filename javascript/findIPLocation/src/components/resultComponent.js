class ResultComponent extends HTMLElement {
    connectedCallback() {}

    set dataResult(dataResult) {
        this._dataResult = dataResult
        this.render()
    }

    render() {
        this.innerHTML = `
        <div class="result">
            <div
                class="bg-gray-200 h-auto flex flex-col shadow-md w-full h-32 my-10 p-10 text-gray-800 font-medium rounded-md">
                <div class="p-2">
                    <h3 class="font-bold text-2xl"># IP</h3>
                    <div class="bg-gray-900 p-2 text-orange-500 rounded-sm pl-6">${this._dataResult.ip}</div>
                </div>
                <div class="p-2">
                    <h3 class="font-bold text-2xl"># Location</h3>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">Negara :</span>
                        <span class="text-orange-500">${this._dataResult.location.country}</span>
                    </div>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">Provinsi :</span>
                        <span class="text-orange-500">${this._dataResult.location.region}</span>
                    </div>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">Kota :</span>
                        <span class="text-orange-500">${this._dataResult.location.city}</span>
                    </div>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">Latitude :</span>
                        <span class="text-orange-500">${this._dataResult.location.lat}</span>
                    </div>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">langtitude :</span>
                        <span class="text-orange-500">${this._dataResult.location.lng}</span>
                    </div>
                    <div class="bg-gray-900 p-2 rounded-sm pl-6">
                        <span class="text-gray-100 ">Kode Pos :</span>
                        <span class="text-orange-500">${this._dataResult.location.postalCode}</span>
                    </div>
                </div>
                <div class="p-2">
                    <h3 class="font-bold text-2xl"># ISP</h3>
                    <div class="bg-gray-900 p-2 text-orange-500 rounded-sm pl-6">${this._dataResult.isp}</div>
                </div>
            </div>
        </div>`
    }
}

customElements.define('result-component', ResultComponent)