import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { Router } from '@angular/router';
import { AuthenticationService } from '../authentication.service';
import { User } from '../models/user';

@Component({
  selector: 'app-login',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent {
  user: User = new User();
  password: string = '';
  formError: string = '';

  constructor(
    private authService: AuthenticationService,
    private router: Router
  ) {}

  onLogin(): void {
    this.formError = '';

    if (!this.user.email || !this.password) {
      this.formError = 'All fields are required';
      return;
    }

    this.authService.login(this.user, this.password).subscribe({
      next: (response) => {
        this.authService.saveToken(response.token);
        this.router.navigate(['/']);
      },
      error: () => {
        this.formError = 'Login failed';
      }
    });
  }
}