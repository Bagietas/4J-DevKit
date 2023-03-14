<?php

require 'global.php';

$message = "Wanna be the new owner ? i sell DownCraft, source + website contact me on Discord Misaki🌸#0911";
echo "<script type='text/javascript'>alert('$message');</script>";

?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="<?= $Controller->Settings('description'); ?>">

    <title><?= $Controller->Settings('name'); ?> - <?= $Controller->Settings('description'); ?></title>

    <link href="assets/css/stylev2.css" rel="stylesheet">
    <link href="assets/css/core.min.css" rel="stylesheet">
    <link href="assets/css/thesaas.min.css" rel="stylesheet">
    <link href="assets/css/style.css" rel="stylesheet">

    <link rel="icon" href="assets/img/favicon.ico">
  </head>

  <body>
</div>
        </div>
		
<audio autoplay>
<source src="music.mp3" type="audio/mpeg">
</audio>

        </div>

      </div>
    </nav>
    <header class="header fadeout header-inverse pb-0 h-fullscreen" style="background-image: linear-gradient(to bottom, #FF5B89 0%, #000000 100%);">
    </video>
      <canvas class="constellation"></canvas>
			
      <div class="container">
        <div class="row h-full">
          <div class="col-12 text-center align-self-center">

            <img src="/assets/img/logo1.png" width="308" height="72" alt="Sigma Logo">

            <h1 class="fs-50 fw-600 lh-15 hidden-sm-down"><span class="text-primary" data-type="RTM Tool, For Minecraft PS3, For Update 1.84, CFW / HEN available"></span></h1>
            <h1 class="fs-35 fw-600 lh-15 hidden-md-up"><span class="text-primary" data-type="RTM Tool, For Minecraft PS3, For Update 1.84, CFW / HEN available"></span></h1>
            <br>
            <p class="fs-20 hidden-sm-down"><strong>Discover DownCraft RTM, the powerful tool for Minecraft PS3</p>

                                        <p class="fs-16 hidden-md-upX"><strong>DownCraft Premium, including DownCraft Demo & SPRX out NOW</strong></p>
            <hr class="w-60 hidden-sm-down">
            <?php if(isset($_SESSION['account'])) { ?>
			<a class="btn btn-xl btn-round btn-primary fs-20 fw-500 w-350 shadow-3 hidden-sm-down" href="/client/">Client area</a>
            <a class="btn btn-lg btn-round btn-primary w-250 shadow-3 hidden-md-up" href="/client/">Client area</a>
			<?php } else { ?>
			<a class="btn btn-xl btn-round btn-primary fs-20 fw-500 w-350 shadow-3 hidden-sm-down" href="/client/login">Download now</a>
            <a class="btn btn-lg btn-round btn-primary w-250 shadow-3 hidden-md-up" href="/client/login">Download now</a>
                        <p class="lead">Windows 10, Windows 8, Windows 7</p>
			<?php } ?>
      <br>
          </div>

          <div class="col-12 align-self-end text-center pb-70">
            <a class="scroll-down-2 scroll-down-inverse" href="#" data-scrollto="section-demo"><span></span></a>
			
          </div>
        </div>
      </div>
    </header>

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<div class="preview" href="/client/" width="200" height="40" id="prev">
<img src="assets/prev.jpg">
</div>
    <main class="main-content">
      <section class="section bg-grey1 pb-0 overflow-hidden hidden-sm-down">
        <div class="container">
          <header class="section-header">
            <h2>.</h2>
            <hr>
            <p class="lead">.</p>
          </header>

          <section class="section bg-grey1 pb-0 overflow-hidden hidden-sm-down">
        <div class="container">
          <header class="section-header">
            <h2>Our counters</h2>
            <hr>
            <p class="lead">Here are our counters. These are updated automatically.</p>
          </header>

          <div class="flexbox flex-grow-all text-center mx-auto w-600">
            
            <div>
              <span class="text-info fs-50"><?= $StingCMS->ADMNbClient(); ?></span><br>
              <p>Member<?= $Controller->isMany($StingCMS->ADMNbClient()); ?> Free</p>
            </div>
            <br>
            <div>
              <span class="text-info fs-50"><?= $StingCMS->ADMNbRetroActif(); ?></span><br>
              <p>Member<?= $Controller->isMany($StingCMS->ADMNbRetroActif()); ?> Premium<?= $Controller->isMany($StingCMS->ADMNbRetroActif()); ?></p>
            </div>
            
          </div>

          <br><br>

          <div class="flexbox flex-grow-all text-center mx-auto w-600">
            <br>
            <div>
              <span class="text-info fs-50"><?= $StingCMS->logs_attach_free(); ?></span><br>
              <p>Free RTM Attach Logs</p>
            </div>
            <br>
            <div>
              <span class="text-info fs-50"><?= $StingCMS->logs_attach_premium(); ?></span><br>
              <p>Premium RTM Attach Logs</p>
            </div>
            
          </div>

          <br><br>

        </div>
      </section>

      <section class="section">
        <div class="container">
          <header class="section-header">
            <h2>Our features</h2>
            <hr>
            <p class="lead">You will learn a little more about us.</p>
          </header>
</div>

          <div class="row gap-y">
			  
            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-tv fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Responsive</h6>
              <p class="fs-14">Our site is compatible on computer, mobile and tablet.</p>
            </div>


            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-wrench fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Custom RTM</h6>
              <p class="fs-14">You have the possibility to modify your RTM at 100%.</p>
            </div>


            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-euro fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Low price</h6>
              <p class="fs-14">Our prices are low so that even small means can order.</p>
            </div>


            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-code fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Own code</h6>
              <p class="fs-14">Our site is developed and improved every day.</p>
            </div>


            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-file-text-o fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Forum</h6>
              <p class="fs-14">A forum is at your disposal to help you.</p>
            </div>


            <div class="col-12 col-md-6 col-xl-4 text-center">
              <i class="fa fa-download fs-25 mb-3 text-secondary"></i>
              <h6 class="fs-18 mb-3">Update</h6>
              <p class="fs-14">We promise to offer you a maximum of update.</p>
            </div>


          </div>
        </div>
      </section>

		<section class="section bg-gray">
        <div class="container">
          <header class="section-header">
            <small>DownCraft</small>
            <h2>More information</h2>
            <hr>
            <p class="lead">Do you want to know more about DownCraft? You are in the right place!</p>
          </header>


          <div class="row gap-y align-items-center">
            <div class="col-12 col-md-5">
              <img class="rounded shadow-2 aos-init" src="assets/img/yh1.png" alt="yh1" data-aos="zoom-in">
            </div>

            <div class="col-12 col-md-7">
              <h4>Payment method</h4>
              <p>Thanks to our Paypal payment solution, you can purchase Premium Version. You can settings your RTM with musics / backgrounds or others features.</p>
            </div>
          </div>


          <hr>


          <hr>


          <div class="row gap-y align-items-center">
            <div class="col-12 col-md-5">
              <img class="rounded shadow-2 aos-init" src="assets/img/yh3.png" alt="yh3" data-aos="zoom-in">
            </div>

            <div class="col-12 col-md-7">
              <h4>Update</h4>
              <p>Want to know the news on our servers? A page containing improvements, incident as well as maintenances is available for you to be informed directly.</p>
            </div>
          </div>



        </div>
      </section>
		
		<section class="section bb-1">
        <div class="container">
          <header class="section-header">
            <h2>Client's opinion</h2>
            <hr>
            <p class="lead">Here are the last 3 reviews from our customers.</p>
          </header>


          <div class="row gap-y">

			  <?php
			  
			  $db = Connect::getDB();
			  
			  $req = $db->query('SELECT * FROM sting_view ORDER BY date DESC LIMIT 3');
			  while($r = $req->fetch()) {
				  $inf = $db->prepare('SELECT * FROM sting_users WHERE clef = ?');
				  $inf->execute(array($r['clef_user']));
				  $f = $inf->fetch();
				  echo '<div class="col-12 col-md-4">
              <div class="card card-shadowed">
                <div class="card-block px-30">
                  <div class="rating mb-12">
                    '.$Controller->Etoile($r['étoile']).'
                  </div>

                  <p class="text-quoted mb-0">'.$r['comment'].'</p>
                  <div class="media align-items-center pb-0">
                    <img class="avatar avatar-xs" src="'.$f['avatar'].'" alt="">
                    <div class="media-body lh-1">
                      <h6 class="mb-0">'.$f['username'].'</h6>
                      <small>@'.$f['username'].'</small>
                    </div>
                  </div>
                </div>
              </div>
            </div>';
			  }
			  
			  ?>
			  
          </div>



        </div>
      </section>
		
	<section class="section">
        <div class="container">
          <header class="section-header">
            <small>DownCraft</small>
            <h2>Staffs</h2>
            <hr>
            <p class="lead">Here is the team of DownCraft</p>
          </header>

          <div class="row gap-y">

			  <?php
			  
			  $db = Connect::getDB();
			  
			  $req = $db->prepare('SELECT * FROM sting_users WHERE rank >= ? ORDER BY rank DESC');
			  $req->execute(array('5'));
			  
			  while($r = $req->fetch()) {
				  echo '<div class="col-12 col-md-4 team-2">
              <a href="#">
                <img src="'.$r['avatar'].'" style="height:80px; width: 80px"  alt="...">
              </a>
              <h5 class="'.$Controller->RankColor($r['rank']).'">'.$r['username'].'</h5>
              <small>'.$Controller->Rank($r['rank']).'</small>
            </div>';
			  }
			  
			  ?>
			  
          </div>
<br>
<br>
<br>

<div class="premiumblock">
<div class="left">
<div class="gem">RTM Premium</div>
<p>
Access exclusive options and mods.</br>
Support developpement and future updates.</br>
The best RTM Premium, even better.
</p>
</div>
<div class="right">
<div class="buy">
<div class="btntitle">Buy</div>

<a href="https://shoppy.gg/product/296nCp0" target="_blank" style="text-decoration: none;"><div class="btndesc" style="color:#631f65;">10.00&euro; / <b>For lifetime</b></div></a>
</div>
</div>
</div>
</div>
<div class="block">
<div class="center">
<h1>Installation is simple</h1>
<img src="http://downcraft.xyz/assets/img/installwindows.png" alt="Install">
</div>
</div>

<div class="block">
<div class="center">
<h1>Videos and Reviews</h1>
<p>Check out these awesome videos.</p>
</br></br></br></br>
<iframe class="youtube" height="296" src="https://www.youtube.com/embed/aNQ0jdfJvnw" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<iframe class="youtube" height="296" src="https://www.youtube.com/embed/7cR7zfhLzVM" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<iframe class="youtube" height="296" src="https://www.youtube.com/embed/oBVCDhbRI3Y" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<iframe class="youtube" height="296" src="https://www.youtube.com/embed/liqg_Oo9EuY" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>
</div>
<div class="footer">
<img src="/assets/img/logo2.png" width="308" height="72" alt="Sigma Logo">
<p>Copyright DownCraft 2018 - 2020 by Misaki Dev. All Rights Reserved.</p>
<center>
  <div class="col-12 col-lg-6">
            <ul class="nav nav-inline nav-primary nav-hero">
              <li class="nav-item">
                <a class="nav-link" href="/client/login">Login</a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="/client/register">Register</a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="/client/">Client area</a>
              </li>
            </ul>
            </center>
          </div>
<div class="modalinit">
<div class="modal-block">
<h1>New updates!</h1>
<iframe width="100%" height="209" src="https://www.youtube.com/" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<p>Some new updates, will come later !</p>
<div class="modal-button" onclick="closeModals()">Close</div>
</div>
</div>
</body>
<script src="https://cdn.jsdelivr.net/particles.js/2.0.0/particles.min.js"></script>
<script>
  particlesJS("particles-js", {"particles":{"number":{"value":69,"density":{"enable":true,"value_area":800}},"color":{"value":"#ffffff"},"shape":{"type":"circle","stroke":{"width":0,"color":"#000000"},"polygon":{"nb_sides":3.7000000000000006},"image":{"src":"","width":250,"height":200}},"opacity":{"value":0.07215332581736189,"random":true,"anim":{"enable":false,"speed":1,"opacity_min":0.1,"sync":false}},"size":{"value":10,"random":true,"anim":{"enable":false,"speed":63,"size_min":0.4700000000000001,"sync":false}},"line_linked":{"enable":false,"distance":150,"color":"#ffffff","opacity":0.4,"width":1},"move":{"enable":true,"speed":1.6,"direction":"none","random":true,"straight":false,"out_mode":"out","bounce":false,"attract":{"enable":false,"rotateX":600,"rotateY":1200}}},"interactivity":{"detect_on":"window","events":{"onhover":{"enable":false,"mode":"repulse"},"onclick":{"enable":false,"mode":"repulse"},"resize":true},"modes":{"grab":{"distance":400,"line_linked":{"opacity":1}},"bubble":{"distance":400,"size":40,"duration":2,"opacity":8,"speed":3},"repulse":{"distance":89.32876538510341,"duration":0.4},"push":{"particles_nb":4},"remove":{"particles_nb":2}}},"retina_detect":true});var count_particles, stats, update; stats = new Stats; stats.setMode(0); stats.domElement.style.position = 'absolute'; stats.domElement.style.left = '0px'; stats.domElement.style.top = '0px'; document.body.appendChild(stats.domElement); count_particles = document.querySelector('.js-count-particles'); update = function() { stats.begin(); stats.end(); if (window.pJSDom[0].pJS.particles && window.pJSDom[0].pJS.particles.array) { count_particles.innerText = window.pJSDom[0].pJS.particles.array.length; } requestAnimationFrame(update); }; requestAnimationFrame(update);;
</script>
<script src="assets/smooth-scroll.js"></script>
<script src="assets/script.js"></script>
<script src="https://embed.selly.io"></script>
<script src="assets/js/core.min.js"></script>
<script src="assets/js/thesaas.min.js"></script>
<script src="assets/js/script.js"></script>
<script src="snowfinish.js"></script>
</html>