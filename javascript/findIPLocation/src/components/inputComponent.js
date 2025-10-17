class InputComponent extends HTMLElement {

    connectedCallback() {
        this.render()
    }

    set onClickEvent(event) {
        this._clickEvent = event
        this.render()
    }

    get value() {
        return this.querySelector('#input').value
    }

    render() {
        this.innerHTML = `
        <div class="flex content-around w-full">
            <input id="input" type="text" class="py-4 px-3 w-full outline-none" placeholder="Cari Siapa ? Ketik IP dan temukan">
            <button id="btn-submit" class="bg-cyan shadow-lg py-3 px-4 w-24 outline-none"><img src="https://img.icons8.com/clouds/100/000000/find-my.png"/></button>
        </div>
        `
        this.querySelector('#btn-submit').addEventListener('click', this._clickEvent)
    }
}

customElements.define('input-component', InputComponent)