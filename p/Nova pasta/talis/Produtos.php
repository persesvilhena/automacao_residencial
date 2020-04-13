<!DOCTYPE html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
    <title>Elite Informática - HOME</title>
    <meta name="description" content="">
    <meta name="viewport" content="width=device-width">
    <link rel="stylesheet" href="css/bootstrap.css">
    <link rel="stylesheet" href="css/bootstrap-responsive.css">
    <link rel="stylesheet" href="css/custom-styles.css">
    <link rel="stylesheet" href="css/component.css">
    <link rel="stylesheet" href="css/font-awesome.css">   

    
</head>

<body>
    <?php include('menu.php'); ?>
    
    <div class="container bg-light-gray">
    <br><br>  




<?php
$conecta = mysqli_connect('localhost', 'root', '', 'siteprojeto');

$sql = "SELECT * FROM Produtos";
$result = mysqli_query($conecta, $sql);
while($prod = mysqli_fetch_array($result)){ 
    
?>

<div class='col-sm-6 col-md-4'>
    <div class='thumbnail'>
      <img width='300' src='img/<?= $prod['imagem'] ?>' alt=''>
      <div class='caption'>
        <h3><?= $prod['nome']; ?></h3>
        <p><a href='ver_produto.php?cod=<?= $prod['codigo'] ?>' class='btn btn-primary' role='button'>Ver Produto</a> 
        <a href='#' class='btn btn-default' role='button'>Button</a></p>
      </div>
    </div>
  </div>



<?php } ?>



    <br><br>
    </div>
    <div class="site-footer">
        <div class="container">
            <div class="row-fluid">
                <div class="span8 offset2">
                    <div class="copy-rights"> Copyright (c). All rights reserved. </div>
                </div>
            </div>
        </div>
        <div class="site-content">
            <p class="last">Designed By: Talis Aparecido</a></p>
    </div>
    <script src="js/jquery-1.9.1.js"></script>
    <script src="js/bootstrap.js"></script>
</body>

</html>