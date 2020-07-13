# Welcome to Voiceless Update Ourwear
sorry late, we had technical difficulty today. and..

Everyone, we have bad news:
- Android Studio suddenly broken forever. idk what caused this.
- It just went blank for any project I opened.
- See? it's dark
- cannot do anything.
- Now I went into VScode this one here.
- Yep, Flutter can work and it just went well here after being created from Android Studio.
- pls help! what to do here.

anyway,

# I've had made serveral features additions!!!
But forgot which one did I add. let's just highlight some
- Rental Item View! Edit rental detail
- Profile Account edit detail!
- Transaction order list!!! what status of those items right now?
- Register Login textfield update untested. Yest@yest.yest
- uh..

# Other stuffs
What was it?
- Last week meeting with coach was skipped because the coach had already important weekly meeting assigned
- Oh no forgot to record that.
- The Adobe XD UI prototype is still on my other member. I still not have one. would ask if so had to
- That Adobe XD UI prototype could be used on the final presentation
- PR haard
- Monthly Report has been submited.

# Neff
Wow, My laptop ram is going to full!  
Nope! you have to login first!
Sorry. the Modal bottom sheet didn't raise up when keyboard appear. I haven't yet figured out this problem.  
Nope! you cannot item that is not yours!  
And yess, the item moves to another category. basically, The transaction queries status da right now. and only imports matching status. We have 8 status!
Let's see how does the transaction imports to temp array variable. please wait!  
Look at that! that's another variable bellow the actual snapshot.data.  
Yes. those code part is to import data for which status is right now.

e.g., if you ask for status 2 (Packed, Dikemas), it only imports data that has status da right now = 2  

Yep, kinda stupid. I query the collection Transaction, all of them one by one. quite inefficient, but it works. idk about your phone later.

it's hard, you know. It's been trial and error to figuring out for this works.

what else...

Oh yess. you just saw the login page. I've added input type so user can have an idea what type of the data it. Though there are some problem, not working or so.

we should logout Yest. then register new Wearer!

the keyboard type is email, correct.

password ok.

phone number input type is number only, correct.

tada! welcome Mr. Tast.

ok. let's see the login again.

email

it works correctly.

how do we specify input type? let's see the Form in one of the page.

with `keyboardType: TextInputType.emailAddress`, on that `TextFormField`.
there are serveral type of the enum of `TextInputType` you can use.

also we should fix the description field. something is going on bad here.

ok where is that....

perhaps it's not `TextFormField`. something else I should figure out later.


oh oh yes!, the submit. I submited the binusmaya PR haard friday or saturday forgot.

oh thursday. ok.

yeah and so..

the vi oh no. forgot to resume. let me look at these again real quick.

oh no! it's going to be 30 minutes! I have to end this video now!

also the read data had some problem, e.g., the Switch for Available did not able to automaticly set.

notice `isAvailable = true`. yep the Saklar data did not read. why. there I gave up. maybe next time.

oh yess. I have been stupid. So when we have been finished presentation and approved, I will remake from scratch, copying some codes into the new Ourwear app. because I forgot to `.gitignore` Google Services JSON file. That supposedly not be seen. that contains API Key. therefore, this is just prototype. cannot use for real business. I should make another Firebase project again for the real business.

and unfortunately, despite finally `.gitignoring` the JSON file, it won't be ignored anymore once it has been commited.

learn the lesson. Just remember to `git append` something if you accidentally commit secret file, before it's too late further commit.

so yeah. 

# Thank you for your attention
Stay at home
Be creative