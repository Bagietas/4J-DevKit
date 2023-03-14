<aside class="sidebar">
		<div class="left-aside-container">
			<div class="user-profile-container">
				<div class="user-profile clearfix">
					<div class="admin-user-thumb">
						<img src="<?= $_SESSION['account']['avatar']; ?>" class="img-circle">
					</div>
					<div class="admin-user-info">
						<ul class="user-info">
							<li><a href="#" class="<?= $Controller->RankColor($_SESSION['account']['rank']); ?> text-semibold text-size-large"><?= $_SESSION['account']['username']; ?></a></li>
							<li><a href="#"><small style="color: #fff"><?= $Controller->Rank($_SESSION['account']['rank']); ?></small></a></li>
						</ul>
						<div class="logout-icon"><a href="?logout=1"><i class="icon-exit2"></i></a></div>
					</div>
					
				</div>				
			</div>						
			<ul class="sidebar-accordion">			
				<li class="list-title">Main</li>
				<li <?php if($page_open == 'accueil') { echo 'class="active"'; } ?>>
					<a href="index"><i class="icon-home2"></i><span class="list-label">Dashboard</span></a>
				</li>
				<li <?php if($page_open == 'equipe') { echo 'class="active"'; } ?>>
					<a href="premium"><i class="icon-users"></i><span class="list-label">All Members Premium</span></a>
				</li>
				<li class="list-title">Download RTM Demo</li>
					<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/demo.php"><i class="icon-download"></i><span class="list-label">RTM Demo Edition V7</span></a>
				</li>
					<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/eboot"><i class="icon-download"></i><span class="list-label">Modded Eboot 1.84</span></a>
				</li>
					<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/sprx"><i class="icon-download"></i><span class="list-label">SPRX Demo V2.1</span></a>
				</li>
					<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/dclient"><i class="icon-download"></i><span class="list-label">DownCraft Client V1.0</span></a>
				</li>
				<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/downcord"><i class="icon-download"></i><span class="list-label">Downcord V1</span></a>
				</li>
                                   <li class="list-title">PURCHASE RTM PREMIUM </li>
				<li <?php if($page_open == 'commander') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/payment/info.php"><i class="icon-cart-add"></i><span class="list-label">Buy RTM Premium ⭐</span></a>
				</li>
				<li class="list-title">Support</li>
				<li <?php if($page_open == 'consulter') { echo 'class="active"'; } ?>>
					<a href="support"><i class="icon-comment-discussion"></i><span class="list-label">My tickets</span></a>
				</li>
				<li <?php if($page_open == 'create') { echo 'class="active"'; } ?>>
					<a href="support?page=create"><i class="icon-plus3"></i><span class="list-label">Create a tickets</span></a>
				</li>
					<?php if($_SESSION['account']['rank'] >= 3) { ?>
				<li class="list-title">*PREMIUM ACCESS*</li>
				<li <?php if($page_open == 'forum') { echo 'class="active"'; } ?>>
					<a href="https://downcraft.xyz/client/premium57.php"><i class="icon-download"></i><span class="list-label">Download Premium ⭐</span></a>
				</li>
				<?php } ?>
				<?php if($_SESSION['account']['rank'] >= 8) { ?>
				<li class="list-title">Administration </li>
				<li>
					<a href="administration/"><i class="icon-key"></i><span class="list-label">Administration <?php echo $StingCMS->ADMNbTickets() ?> tickets</span></a>
				</li>
				<?php } ?>
			</ul>	
		</div>
	</aside>