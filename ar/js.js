function AlteraRele(id){
	var estado = document.getElementById('estado' + id).innerHTML;
	if(estado === '0'){
		document.getElementById('estado' + id).innerHTML='1';
		document.getElementById('botao' + id).innerHTML='<a href=/?desligar' + id + '>Desligar Rele ' + id + '</a>';
		document.getElementById('botao' + id).className='botao_des';
	} else {
		document.getElementById('estado' + id).innerHTML='0';
		document.getElementById('botao' + id).innerHTML='<a href=/?ligar' + id + '>Ligar Rele ' + id + '</a>';
		document.getElementById('botao' + id).className='botao_lig';
	}
}