<?php
include('navbar.php')
?>

    <!-- Header Start -->
    <div class="jumbotron jumbotron-fluid page-header position-relative overlay-bottom" style="margin-bottom: 90px;">
        <div class="container text-center py-5">
            <h1 class="text-white display-1">Course Detail</h1>
            <div class="d-inline-flex text-white mb-5">
                <p class="m-0 text-uppercase"><a class="text-white" href="">Home</a></p>
                <i class="fa fa-angle-double-right pt-1 px-3"></i>
                <p class="m-0 text-uppercase">Course Detail</p>
            </div>
            <div class="mx-auto mb-5" style="width: 100%; max-width: 600px;">
                <div class="input-group">
                    <div class="input-group-prepend">
                        <button class="btn btn-outline-light bg-white text-body px-4 dropdown-toggle" type="button" data-toggle="dropdown"
                            aria-haspopup="true" aria-expanded="false">Courses</button>
                        <div class="dropdown-menu">
                            <a class="dropdown-item" href="#">Courses 1</a>
                            <a class="dropdown-item" href="#">Courses 2</a>
                            <a class="dropdown-item" href="#">Courses 3</a>
                        </div>
                    </div>
                    <input type="text" class="form-control border-light" style="padding: 30px 25px;" placeholder="Keyword">
                    <div class="input-group-append">
                        <button class="btn btn-secondary px-4 px-lg-5">Search</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!-- Header End -->


    <!-- Detail Start -->
    <div class="container-fluid py-5">
        <div class="container py-5">
            <div class="row">
                <div class="col-lg-8">
                    <div class="mb-5">
                        <div class="section-title position-relative mb-5">
                            <h6 class="d-inline-block position-relative text-secondary text-uppercase pb-2">Course Detail</h6>
                            <h1 class="display-4">Web design & development courses for beginners</h1>
                        </div>
                        <img class="img-fluid rounded w-100 mb-4" src="img/header.jpg" alt="Image">
                        <p>Tempor erat elitr at rebum at at clita aliquyam consetetur. Diam dolor diam ipsum et, tempor voluptua sit consetetur sit. Aliquyam diam amet diam et eos sadipscing labore. Clita erat ipsum et lorem et sit, sed stet no labore lorem sit. Sanctus clita duo justo et tempor consetetur takimata eirmod, dolores takimata consetetur invidunt magna dolores aliquyam dolores dolore. Amet erat amet et magna</p>
                        
                        <p>Sadipscing labore amet rebum est et justo gubergren. Et eirmod ipsum sit diam ut magna lorem.
                            Nonumy vero labore lorem sanctus rebum et lorem magna kasd, stet amet magna accusam
                            consetetur eirmod. Kasd accusam sit ipsum sadipscing et at at sanctus et. Ipsum sit
                            gubergren dolores et, consetetur justo invidunt at et aliquyam ut et vero clita. Diam sea
                            sea no sed dolores diam nonumy, gubergren sit stet no diam kasd vero.</p>
                    </div>

                    <h2 class="mb-3">Related Courses</h2>
                    <div class="owl-carousel related-carousel position-relative" style="padding: 0 30px;">
                        <a class="courses-list-item position-relative d-block overflow-hidden mb-2" href="detail.html">
                            <img class="img-fluid" src="img/courses-1.jpg" alt="">
                            <div class="courses-text">
                                <h4 class="text-center text-white px-3">Web design & development courses for
                                    beginners</h4>
                                <div class="border-top w-100 mt-3">
                                    <div class="d-flex justify-content-between p-4">
                                        <span class="text-white"><i class="fa fa-user mr-2"></i>Jhon Doe</span>
                                        <span class="text-white"><i class="fa fa-star mr-2"></i>4.5
                                            <small>(250)</small></span>
                                    </div>
                                </div>
                            </div>
                        </a>
                        <a class="courses-list-item position-relative d-block overflow-hidden mb-2" href="detail.html">
                            <img class="img-fluid" src="img/courses-2.jpg" alt="">
                            <div class="courses-text">
                                <h4 class="text-center text-white px-3">Web design & development courses for
                                    beginners</h4>
                                <div class="border-top w-100 mt-3">
                                    <div class="d-flex justify-content-between p-4">
                                        <span class="text-white"><i class="fa fa-user mr-2"></i>Jhon Doe</span>
                                        <span class="text-white"><i class="fa fa-star mr-2"></i>4.5
                                            <small>(250)</small></span>
                                    </div>
                                </div>
                            </div>
                        </a>
                        <a class="courses-list-item position-relative d-block overflow-hidden mb-2" href="detail.html">
                            <img class="img-fluid" src="img/courses-3.jpg" alt="">
                            <div class="courses-text">
                                <h4 class="text-center text-white px-3">Web design & development courses for
                                    beginners</h4>
                                <div class="border-top w-100 mt-3">
                                    <div class="d-flex justify-content-between p-4">
                                        <span class="text-white"><i class="fa fa-user mr-2"></i>Jhon Doe</span>
                                        <span class="text-white"><i class="fa fa-star mr-2"></i>4.5
                                            <small>(250)</small></span>
                                    </div>
                                </div>
                            </div>
                        </a>
                    </div>
               </div>

                <div class="col-lg-4 mt-5 mt-lg-0">
                    <div class="bg-primary mb-5 py-3">
                        <h3 class="text-white py-3 px-4 m-0">Course Features</h3>
                        <div class="d-flex justify-content-between border-bottom px-4">
                            <h6 class="text-white my-3">Instructor</h6>
                            <h6 class="text-white my-3">John Doe</h6>
                        </div>
                        <div class="d-flex justify-content-between border-bottom px-4">
                            <h6 class="text-white my-3">Rating</h6>
                            <h6 class="text-white my-3">4.5 <small>(250)</small></h6>
                        </div>
                        <div class="d-flex justify-content-between border-bottom px-4">
                            <h6 class="text-white my-3">Lectures</h6>
                            <h6 class="text-white my-3">15</h6>
                        </div>
                        <div class="d-flex justify-content-between border-bottom px-4">
                            <h6 class="text-white my-3">Duration</h6>
                            <h6 class="text-white my-3">10.00 Hrs</h6>
                        </div>
                        <div class="d-flex justify-content-between border-bottom px-4">
                            <h6 class="text-white my-3">Skill level</h6>
                            <h6 class="text-white my-3">All Level</h6>
                        </div>
                        <div class="d-flex justify-content-between px-4">
                            <h6 class="text-white my-3">Language</h6>
                            <h6 class="text-white my-3">English</h6>
                        </div>
                        <h5 class="text-white py-3 px-4 m-0">Course Price: $199</h5>
                        <div class="py-3 px-4">
                            <a class="btn btn-block btn-secondary py-3 px-5" href="">Enroll Now</a>
                        </div>
                    </div>

                    <div class="mb-5">
                        <h2 class="mb-3">Categories</h2>
                        <ul class="list-group list-group-flush">
                            <li class="list-group-item d-flex justify-content-between align-items-center px-0">
                                <a href="" class="text-decoration-none h6 m-0">Web Design</a>
                                <span class="badge badge-primary badge-pill">150</span>
                            </li>
                            <li class="list-group-item d-flex justify-content-between align-items-center px-0">
                                <a href="" class="text-decoration-none h6 m-0">Web Development</a>
                                <span class="badge badge-primary badge-pill">131</span>
                            </li>
                            <li class="list-group-item d-flex justify-content-between align-items-center px-0">
                                <a href="" class="text-decoration-none h6 m-0">Online Marketing</a>
                                <span class="badge badge-primary badge-pill">78</span>
                            </li>
                            <li class="list-group-item d-flex justify-content-between align-items-center px-0">
                                <a href="" class="text-decoration-none h6 m-0">Keyword Research</a>
                                <span class="badge badge-primary badge-pill">56</span>
                            </li>
                            <li class="list-group-item d-flex justify-content-between align-items-center px-0">
                                <a href="" class="text-decoration-none h6 m-0">Email Marketing</a>
                                <span class="badge badge-primary badge-pill">98</span>
                            </li>
                        </ul>
                    </div>

                    <div class="mb-5">
                        <h2 class="mb-4">Recent Courses</h2>
                        <a class="d-flex align-items-center text-decoration-none mb-4" href="">
                            <img class="img-fluid rounded" src="img/courses-80x80.jpg" alt="">
                            <div class="pl-3">
                                <h6>Web design & development courses for beginners</h6>
                                <div class="d-flex">
                                    <small class="text-body mr-3"><i class="fa fa-user text-primary mr-2"></i>Jhon Doe</small>
                                    <small class="text-body"><i class="fa fa-star text-primary mr-2"></i>4.5 (250)</small>
                                </div>
                            </div>
                        </a>
                        <a class="d-flex align-items-center text-decoration-none mb-4" href="">
                            <img class="img-fluid rounded" src="img/courses-80x80.jpg" alt="">
                            <div class="pl-3">
                                <h6>Web design & development courses for beginners</h6>
                                <div class="d-flex">
                                    <small class="text-body mr-3"><i class="fa fa-user text-primary mr-2"></i>Jhon Doe</small>
                                    <small class="text-body"><i class="fa fa-star text-primary mr-2"></i>4.5 (250)</small>
                                </div>
                            </div>
                        </a>
                        <a class="d-flex align-items-center text-decoration-none mb-4" href="">
                            <img class="img-fluid rounded" src="img/courses-80x80.jpg" alt="">
                            <div class="pl-3">
                                <h6>Web design & development courses for beginners</h6>
                                <div class="d-flex">
                                    <small class="text-body mr-3"><i class="fa fa-user text-primary mr-2"></i>Jhon Doe</small>
                                    <small class="text-body"><i class="fa fa-star text-primary mr-2"></i>4.5 (250)</small>
                                </div>
                            </div>
                        </a>
                        <a class="d-flex align-items-center text-decoration-none" href="">
                            <img class="img-fluid rounded" src="img/courses-80x80.jpg" alt="">
                            <div class="pl-3">
                                <h6>Web design & development courses for beginners</h6>
                                <div class="d-flex">
                                    <small class="text-body mr-3"><i class="fa fa-user text-primary mr-2"></i>Jhon Doe</small>
                                    <small class="text-body"><i class="fa fa-star text-primary mr-2"></i>4.5 (250)</small>
                                </div>
                            </div>
                        </a>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!-- Detail End -->
<?php
include('footer.php')
?>